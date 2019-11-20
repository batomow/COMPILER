#include <stdio.h> 
#include <stdlib.h> 
#include "jedi.h"

FTE NewFTE(){
    FTE r;
    r.isSet = 0; 
    r.moduleid = ""; 
    r.returntype = TypeNull; 
    r.quadlinenum = -1; 
    r.size = 0; 
    r.params = NULL; 
    r.vars = NULL; 
    r.next = NULL; 
    return r; 
}

void SetFTE(FTE* fte, char* moduleid, TableType returntype, int quadline){
    fte->isSet = 1; 
    fte->moduleid = moduleid; 
    fte->returntype = returntype; 
    fte->params = calloc(1, sizeof(VarTable)); 
    *(fte->params) = NewVarTable(23); 
    fte->vars = calloc(1, sizeof(VarTable)); 
    *(fte->vars) = NewVarTable(127); 
    fte->next = calloc(1, sizeof(FTE)); 
    *(fte->next) = NewFTE();  
}

int getBytes(TableType type, int size){
    switch(type){
        case TableInt: 
        case TableFloat: 
        case TableDouble: 
        case TableChar:
        case TableString: return sizeof(Var)*size; break; 
        case TableElement: return sizeof(Element)*size; break; 
        case TableVector: return sizeof(Vector)*size; break; 
        default: return 0; break; 
    }
}

void UpdateTotalSize(FTE* fte){
    int totalBytes = 0; 
    VTE* iter; 
    for(int n = 0; n<fte->params->size; n++){
        iter = (fte->params->__dict+n);
        while(iter->isSet){
            totalBytes += getBytes(iter->type, iter->dim->size); 
            iter = iter->next; 
        }
    }
    for(int n = 0; n<fte->vars->size; n++){
        iter = (fte->vars->__dict+n); 
        while(iter->isSet){
            totalBytes += getBytes(iter->type, iter->dim->size); 
            iter = iter->next; 
        }
    }
    fte->size = totalBytes; 
}

void DestroyFTE(FTE* iter){
    if(iter->isSet){
       DestroyFTE(iter->next);  
       DestroyVarTable(iter->params); 
       DestroyVarTable(iter->vars); 
    }
    iter->isSet = 0; 
    free(iter->params); 
    free(iter->vars); 
    free(iter); 
}
