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

DIM NewDIM(){
    DIM r; 
    r.isSet = 0; 
    r.limsup = 0; 
    r.step = 0; 
    r.next = NULL; 
    return r; 
}

void SetDIM(DIM* dim, int limsup, int step){
    dim->isSet = 1; 
    dim->limsup = limsup; 
    dim->step = step; 
    dim->next = calloc(1, sizeof(DIM));//allocate memory 
    *(dim->next) = NewDIM(); //set whats in memory
}


void DestroyDIM(DIM* dim){
    if(dim->isSet){
        DestroyDIM(dim->next); 
        dim->isSet = 0; 
        dim->limsup = 0; 
        dim->step = 0; 
        free(dim);
    }
}

VarTableEntry NewVarTableEntry(){
    VarTableEntry r; 
    r.type = TableNull; 
    r.isSet = 0; 
    r.dir = 0; 
    r.dim = NULL; 
    return r; 
}

void SetVarTableEntry(VarTableEntry* vte, char* id, TableType type, int dir, DIM dim){
    vte->isSet = 1; 
    vte->type = type; 
    vte->id = id; 
    vte->dir = dir; 
    vte->dim = calloc(1, sizeof(DIM)); 
    *(vte->dim) = dim;  
    vte->next = calloc(1, sizeof(VarTableEntry));  //allocate memory
    *(vte->next) =  NewVarTableEntry();  //set whats in that memory 
}

void DestroyVarTableEntry(VarTableEntry* vte){
    if(vte->isSet){
        DestroyVarTableEntry(vte->next); 
        DestroyDIM(vte->dim); 
    }
    vte->isSet = 0; 
    free(vte); 
}

int __is_table_empty(VarTable* t){
    return (t->__current_size > 0 ? 0 : 1); 
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
    default: return "Not Defined"; break; 
    }
}

int __dim2String(DIM dim){
    if(!dim.isSet)
        return 0; 
    if(dim.next->isSet)
        return (dim.limsup)*(dim.next->limsup);
    return dim.limsup; 
}

void __print_var_table(VarTable* t){
    if (t->isEmpty(t))
        return; 
    printf("\n"); 
    VarTableEntry* iter; 
    int counter = 0; 
    for(int n = 0; n<t->size; n++){
        iter = (t->__dict+n); 
        counter = 0; 
        if(!iter->isSet)
            continue; 
        while(iter->isSet){
            for(int i = 0; i<counter; i++)
                printf("->"); 
            printf("[%d|%s|%s|%d|%d]\n", n, iter->id, __enum2String(iter->type), iter->dir, __dim2String(*(iter->dim))); 
            iter = iter->next; 
            counter++; 
        }
    }
}

VarTable NewVarTable(int size){
    VarTable D; 
    TRY{
        D.__dict = calloc(size, sizeof(VarTableEntry)); 
        if (D.__dict == NULL)
            THROW; 
        D.size = size; 
    }CATCH{
        printf("size exceded available memory, halving size\n"); 
        D.__dict = calloc(size/2, sizeof(VarTableEntry)); 
        D.size = size/2; 
    }ETRY;  
    for(int n = 0; n<D.size; n++)
        D.__dict[n] = NewVarTableEntry();  
    D.print = &__print_var_table; 
    D.isEmpty = &__is_table_empty; 
    D.__current_size = 0; 
    return D; 
}

VarTableEntry TableLookup(VarTable* table, char* id){
    int hash  = __hash(id, table->size); 
    VarTableEntry* iter = &(table->__dict[hash]); 
    while(iter->isSet){
        if (strcmp(iter->id, id) == 0)
            return *iter; 
        iter = iter->next; 
    }
    return NewVarTableEntry(); 
}

int InsertVar(VarTable* table, char* id, TableType type, int dir, DIM dim){
    int hash = __hash(id, table->size); 
    VarTableEntry* iter = &(table->__dict[hash]); 
    while(iter->isSet){
        if (strcmp(iter->id, id) == 0)
            return 0; 
        iter = iter->next; 
    }
    SetVarTableEntry(iter, id, type, dir, dim); 
    table->__current_size++; 
    return 1; 
}

void DestroyTable(VarTable* table){
    for(int n = 0; n<table->size; n++)
        if(table->__dict[n].isSet){
            DestroyVarTableEntry(&(table->__dict[n])); 
        }
}

