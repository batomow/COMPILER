#include <stdlib.h> 
#include <stdio.h> 
#include "jedi.h"

int __hash(Var item, int size){
    int hash = 0; 
    if(item.type == TypeInt){
       hash = item.data.iVal % size; 
    }
    if (item.type == TypeFloat){
        hash = ((int)item.data.fVal) % size;  
    }
    if (item.type == TypeDouble){
        hash = ((int)item.data.dVal) % size; 
    }
    if (item.type == TypeChar){
       hash = ((int)item.data.cVal) % size;  
    }
    if (item.type == TypeString){
       char* word = item.data.sVal; 
       for(hash = 0; *word != '\0'; word++){
            hash = hash^(*word); 
       }
    }
    return hash % size; 
}

KeyValuePair NewKeyValuePair(Var key, Var value){
    KeyValuePair newkvp; 
    newkvp.key = key; 
    newkvp.value = value; 
    return newkvp; 
}

int __dict_is_empty(Dictionary* dict){
    if (dict->size <= 0)
        return 1; 
    return 0; 
}

void __print_dict(Dictionary* D){
    for(int n = 0; n<D->size; n++){
        KeyValuePair* iter = &D->__dict[n];
        while(iter->next){
            char* val = VarToString(iter->value); 
            char* key = VarToString(iter->key); 
            printf("Key:%s\tVal:%s\n", key, val); 
            free(key); 
            free(val); 
            if (iter->next) iter = iter->next; 
        }
    }
}

Dictionary NewDictionary(int size){
    Dictionary newDict; 
    newDict.__dict = (KeyValuePair*)calloc(size, sizeof(KeyValuePair)); 
    newDict.size = size; 
    newDict.is_empty = &__dict_is_empty;
    newDict.print = &__print_dict; 
    return newDict; 
}

void add(Dictionary* D, Var K, Var V){
    int hash = __hash(K, D->size); 
    KeyValuePair* iter = &D->__dict[hash];
    if (iter){
        while(iter->next){
            iter->next->prev = iter; 
            iter = iter->next;
        }
    }
    *iter = NewKeyValuePair(K, V); 
    iter->next = (KeyValuePair*)calloc(1, sizeof(KeyValuePair));
}

void add_pair(Dictionary* D, KeyValuePair kvp){
    add(D, kvp.key, kvp.value); 
}

Var lookup(Dictionary* D, Var key){
    int hash = __hash(key, D->size); 
    KeyValuePair* iter = &D->__dict[hash]; 
    if(iter->next){
        printf("%s %s\n", iter->key.data.sVal, key.data.sVal); 
        if(EqualVars(iter->key, key))
            return iter->value;
        iter = iter->next;
    }else if (EqualVars(iter->key, key)){
        return iter->value;
    }
    return NewVarS("No result"); 
}
