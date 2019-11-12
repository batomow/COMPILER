#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include "jedi.h"
#include <math.h>


unsigned long __hash(char* word, int size){
    unsigned long hash = 5391; 
    int c; 
    while((c = *word++)){
        hash = ((hash<<5)+hash) + c; 
    }
    return hash % size; 
}

void printDict(Dictionary* d){
    printf("\n");
    char* aux; 
    int counter; 
    for(int n = 0; n<d->size; n++){
        kvp* iter = (d->__dict+n); 
        counter = 0; 
        if (!iter->isSet)
            continue; 
        while(iter->isSet){
            for(int i = 0; i<counter; i++)
                printf("->"); 
            aux = VarToString(iter->value); 
            printf("|%s|%s]\n", iter->key, aux); 
            iter = iter->next; 
            counter++; 
        }
        free(aux); 
    }
}

int __dict_is_empty(Dictionary* D){
    D->size >= 1 ? 0 : 1; 
}

Dictionary NewDictionary(int size){
    Dictionary D; 
    TRY{
        D.__dict = calloc(size, sizeof(struct KeyValuePair)); 
        if (D.__dict == NULL)
            THROW; 
        D.size = size; 
    }CATCH{
        printf("size exceded available memory, halving size\n"); 
        D.__dict = calloc(size/2, sizeof(struct KeyValuePair)); 
        D.size = size/2; 
    }ETRY;  
    for(int n = 0; n<D.size; n++)
        D.__dict[n] = NewKeyValuePair(); 
    D.print = &printDict; 
    D.isEmpty = &__dict_is_empty; 
    return D; 
}

kvp NewKeyValuePair(){
    struct KeyValuePair result; 
    result.next = NULL; 
    result.isSet = 0; 
    result.key = ""; 
    result.value = NullVar(); 
    return result; 
}

void setkvp(kvp* item, char* key, Var value){
    item->isSet = 1; 
    item->key = key; 
    item->value = value; 
    item->next = calloc(1, sizeof(kvp));  //allocate memory
    *(item->next) = NewKeyValuePair();  //set whats in that memory
}

void DestroyEntry(kvp* item){
    if(item->isSet)
        DestroyEntry(item->next); 
    item->next = NULL; 
    item->key = NULL; 
    item->isSet = 0; 
    free(item); 
}

void DestroyDictionary(Dictionary* d){
    for(int n = 0; n<d->size; n++)
        DestroyEntry(d->__dict+n); 
    free(d->__dict);
    d->__dict = NULL; 
}


int add(Dictionary* d, char* key, Var value){
    unsigned long int hash = __hash(key, d->size); 
    kvp* iter = &(d->__dict[hash]);
    while(iter->isSet){
        if(strcmp(key, iter->key) == 0)
            return 0; 
        iter = iter->next; 
    }
    setkvp(iter, key, value); 
    return 1; 
}

Var lookup(Dictionary* d, char* key){
    unsigned long int hash = __hash(key, d->size); 
    kvp* iter = &(d->__dict[hash]); 
    while(iter->isSet){
        if(strcmp(key, iter->key) == 0)
            return iter->value;
        iter = iter->next;
    }
    return NewVarS("Not found"); 
}

int remove_entry(Dictionary* d, char* key){
    unsigned long int hash = __hash(key, d->size); 
    kvp* iter = &(d->__dict[hash]); 
    kvp* prev_iter; 
    while(iter->isSet){
        if(strcmp(key, iter->key) == 0){
            if(iter->next){
                prev_iter->next = iter->next; 
                free(iter); 
            }
        }
        prev_iter = iter; 
        iter = iter->next;
    }
    return 0;
}
    
char** get_keys(Dictionary* d, int *keySize){
    int numKeys = 0, currSize = d->size;  
    char** keys = (char**)calloc(d->size, sizeof(char*)); 
    for(int n = 0; n<d->size; n++){
        kvp* iter = (d->__dict+n); 
        if (!iter->isSet)
            continue; 
        while(iter->isSet){
            if (numKeys >= currSize){
                keys = (char**)realloc(keys, (currSize)*2*sizeof(char*)); 
                currSize *= 2; 
            }
            keys[numKeys] = iter->key; 
            numKeys++; 
            iter = iter->next; 
        }
    }
    *keySize = numKeys; 
    return keys; 
}

Var* get_values(Dictionary* d, int *valSize){
    int numVals = 0, currSize = d->size;  
    Var* values = (Var*)calloc(d->size, sizeof(Var)); 
    for(int n = 0; n<d->size; n++){
        kvp* iter = (d->__dict+n); 
        if (!iter->isSet)
            continue; 
        while(iter->isSet){
            if (numVals >= currSize){
                values = (Var*)realloc(values, (currSize)*2*sizeof(Var)); 
                currSize *= 2; 
            }
            values[numVals] = iter->value; 
            numVals++; 
            iter = iter->next; 
        }
    }
    *valSize = numVals; 
    return values; 
}

