#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 
#include <string.h> 
#include <math.h> 



unsigned long HASH(char* word, int size){
    unsigned long hash = 5391; 
    int c; 
    while((c = *word++)){
        hash = ((hash<<5)+hash) + c; 
    }
    return hash % size; 
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
    return D; 
}

kvp NewKeyValuePair(){
    struct KeyValuePair result; 
    result.next = NULL; 
    result.isSet = 0; 
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

int add(Dictionary* d, char* key, Var value){
    unsigned long int hash = HASH(key, d->size); 
    printf("%lu \t", hash); 
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
    unsigned long int hash = HASH(key, d->size); 
    kvp* iter = &(d->__dict[hash]); 
    while(iter->isSet){
        if(strcmp(key, iter->key) == 0)
            return iter->value;
        iter = iter->next;
    }
    return NewVarS("Not found"); 
}

int main(){ 
    Dictionary test = NewDictionary(10); 
    add(&test, "Carlos", NewVarS("Miranda")); 
    add(&test, "Cristhel", NewVarS("Rubio")); 
    add(&test, "Nicolas", NewVarS("-------")); 
    add(&test, "Ian", NewVarS("Granados")); 
    add(&test, "TOM", NewVarS("........")); 
    add(&test, "solrac", NewVarS("--------")); 
    printDict(&test); 
    char* key = "Ian"; 
    Var lastname = lookup(&test, key); 
    char* aux; 
    aux = VarToString(lastname); 
    printf("%s: %s\n", key, aux);
    free(aux); 
    DestroyDictionary(&test); 
    
    return 0; 
}
