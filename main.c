#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 

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
    r.liminf = 0; 
    r.limsup = 0; 
    r.step = 0; 
    r.next = NULL; 
    return r; 
}

void setDIM(DIM* dim, int liminf, int limsup, int step){
    dim->isSet = 1; 
    dim->liminf = liminf; 
    dim->limsup = limsup; 
    dim->step = step; 
    dim->next = calloc(1, sizeof(DIM));//allocate memory 
    *(dim->next) = NewDIM(); //set whats in memory
}


void DestroyDIM(DIM* dim){
    if(dim->isSet)
        DestroyDIM(dim->next); 
    dim->isSet = 0; 
    dim->liminf = 0; 
    dim->limsup = 0; 
    dim->step = 0; 
    free(dim); 
}

VarTableEntry NewVarTableEntry(){
    VarTableEntry r; 
    r.isSet = 0; 
    r.data = NullVar(); 
    r.dir = 0; 
    r.dim = NULL; 
    return r; 
}

void PresetVarTableEntry(VarTableEntry* vte, DataType type, int dir, DIM dim){
    vte->isSet = 1; 
    vte->data = NullVar(); 
    vte->type = type; 
    vte->dir = dir; 
    vte->dim = calloc(1, sizeof(DIM)); 
    *(vte->dim) = dim;  
}

void SetVarTableEntry(VarTableEntry* vte, Var data){
    vte->data = data; 
}

void DestroyVarTableEntry(VarTableEntry* vte){
    vte->isSet = 0; 
    DestroyDIM(vte->dim); 
}

int main(){ 
    DIM dimension1 = NewDIM(); 
    setDIM(&dimension1, 0, 3, 1); 
    VarTableEntry variableA = NewVarTableEntry(); 
    PresetVarTableEntry(&variableA, TypeInt, 5000, dimension1);  
    return 0; 
}
