#include <stdio.h> 
#include <stdlib.h> 
#include "jedi.h" 
#include <string.h> 
#include <math.h> 

unsigned long __hash(char* word, int size){
    unsigned long hash = 5391; 
    int c; 
    while((c = *word++)){
        hash = ((hash<<5)+hash) + c; 
    }
    return hash % size; 
}

void __DIMToStringRecurring(DIM* dim, char* result){
    if(dim->isSet){
        char* aux = (char*)calloc(21, sizeof(char)); 
        sprintf(aux, "->[0|%d|m:%d]", dim->limsup, dim->step); 
        strcat(result, aux); 
        free(aux); 
        __DIMToStringRecurring(dim->next, result); 
    }
}

char* __DIMToString(DIM* dim){ //needs deallocation
    char* result  = (char*)calloc(140, sizeof(char)); 
    if(dim->isSet)
        __DIMToStringRecurring(dim, result); 
    return result; 
}

DIM NewDIM(){
    DIM r; 
    r.isSet = 0; 
    r.limsup = 0; 
    r.step = 0; 
    r.next = NULL; 
    r.toString = &__DIMToString; 
    r.size = 1; 
    return r; 
}

void SetDIM(DIM* dim, int limsup, int step){
    dim->isSet = 1; 
    dim->limsup = limsup; 
    dim->step = step; 
    dim->next = calloc(1, sizeof(DIM));//allocate memory 
    *(dim->next) = NewDIM(); //set whats in memory
    dim->size = limsup; //defaults to limsup
}


void __AddDIMRecurring(DIM* iter, DIM* newdim, int* size, int* m){
    if(iter->isSet){
        *size *= iter->limsup;  //multiplicatoria
        __AddDIMRecurring(iter->next, newdim, size, m); 
    } else{
        *size *= newdim->limsup; 
        SetDIM(iter, newdim->limsup, 1);//last dim 
        *m = newdim->limsup; 
        return; 
    }
    iter->step = *m; 
    *m *= iter->limsup; 
}

void AddDIM(DIM* base, DIM* newdim){
    int size = 1, m = 0; 
    if(base->isSet){
        __AddDIMRecurring(base, newdim, &size, &m); 
        base->size = size;//recalculate the size 
    }
}


void DestroyDIM(DIM* dim){
    if(dim) {
        if(dim->isSet){
            DestroyDIM(dim->next); 
            dim->isSet = 0; 
            dim->limsup = 0; 
            dim->step = 0; 
        }
        free(dim); 
    }
}

VTE NewVTE(){
    VTE r; 
    r.type = TableNull; 
    r.isSet = 0; 
    r.dir = 0; 
    r.dim = NULL; 
    r.next = NULL; 
    return r; 
}

void SetVTE(VTE* vte, char* id, TableType type, int dir, DIM* dim){
    vte->isSet = 1; 
    vte->type = type; 
    vte->id = id; 
    vte->dir = dir; 
    vte->dim = dim; 
    vte->next = calloc(1, sizeof(VTE));  //allocate memory
    *(vte->next) =  NewVTE();  //set whats in that memory 
}

void DestroyVTE(VTE* vte){
    DestroyDIM(vte->dim); 
    if(vte->isSet){
        DestroyVTE(vte->next);  
        vte->isSet = 0; 
    }
    free(vte); 
}

int __is_table_empty(VarTable* t){
    return (t->__current_size == 0 ? 1 : 0); 
}

char* __enum2String(TableType tt){
    switch(tt){
    case 0 : return "Int"; break;  
    case 1: return "Float"; break; 
    case 2: return "Char"; break; 
    case 3: return "String"; break; 
    case 4: return "Element"; break; 
    case 5: return "Vector"; break; 
    case 6: return "(null)"; break; 
    case 7: return "Double"; break; 
    case 8: return "Bool"; break; 
    default: return "Not Defined"; break; 
    }
}


void __print_var_table(VarTable* t){
    if (t->isEmpty(t)){
        printf("[empty]\n");     
        return; 
    }
    VTE* iter; 
    int counter = 0; 
    for(int n = 0; n<t->size; n++){
        iter = (t->__dict+n); 
        counter = 0; 
        if(!iter->isSet)
            continue; 
        while(iter->isSet){
            for(int i = 0; i<counter; i++)
                printf("->"); 
            char* aux = iter->dim->toString(iter->dim); 
            printf("\t[%d|%s|%s|%d| o-]%s\n", n, iter->id, __enum2String(iter->type), iter->dir, aux); 
            free(aux); 
            iter = iter->next; 
            counter++; 
        }
    }
}


VTE* __vartable_lookup(VarTable* table, char* id){
    int hash  = __hash(id, table->size); 
    VTE* iter = &(table->__dict[hash]); 
    while(iter->isSet){
        if (strcmp(iter->id, id) == 0)
            return iter; 
        iter = iter->next; 
    }
    iter = calloc(1, sizeof(VTE)); *iter = NewVTE(); 
    return iter;  
}

int __vartable_add(VarTable* table, char* id, TableType type, int dir, DIM* dim){
    int hash = __hash(id, table->size); 
    VTE* iter = (table->__dict + hash); 
    while(iter->isSet){
        if (strcmp(iter->id, id) == 0)
            return 0; 
        iter = iter->next; 
    }
    SetVTE(iter, id, type, dir, dim); 
    table->__current_size++; 
    return 1; 
}

void __vartable_remove(VarTable* table, char* id){
    int hash = __hash(id, table->size); 
    VTE* iter = (table->__dict+hash); 
    while(iter->isSet){ 
        if(strcmp(id, iter->id) == 0){
            DestroyDIM(iter->dim); 
            while(iter->next->isSet){
                iter->id = iter->next->id; 
                iter->type = iter->next->type; 
                iter->dir = iter->next->dir; 
                iter->dim = iter->next->dim; 
                iter = iter->next; 
            }
            iter->dim = NULL; 
            iter->isSet = 0; 
            iter->id = "deleted";
            free(iter->next); 
            return; 
        }
        iter = iter->next;
    }
}

void DestroyVarTable(VarTable* table){
    VTE* iter = table->__dict; 
    for(int n = 0; n<table->size; n++){
        if((iter+n)->isSet){
            DestroyDIM((iter+n)->dim); 
            DestroyVTE((iter+n)->next);  
        }
    }
    free(table->__dict); 
}

VarTable NewVarTable(int size){
    VarTable D; 
    TRY{
        D.__dict = calloc(size, sizeof(VTE)); 
        if (D.__dict == NULL)
            THROW; 
        D.size = size; 
    }CATCH{
        printf("size exceded available memory, halving size\n"); 
        D.__dict = calloc(size/2, sizeof(VTE)); 
        D.size = size/2; 
    }ETRY;  
    for(int n = 0; n<D.size; n++)
        D.__dict[n] = NewVTE();  
    D.print = &__print_var_table; 
    D.isEmpty = &__is_table_empty; 
    D.__current_size = 0; 
    D.add = &__vartable_add; 
    D.remove = &__vartable_remove; 
    D.lookup = &__vartable_lookup; 
    return D; 
}
