#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 
#include "jedi.h"

unsigned long __hash3(char* word, int size){
    unsigned long hash = 5391; 
    int c; 
    while((c = *word++)){
        hash = ((hash<<5)+hash) + c; 
    }
    return hash % size; 
}

char* __enumToString(TableType tt){
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

FTE NewFTE(){
    FTE r;
    r.isSet = 0; 
    r.moduleid = ""; 
    r.returntype = TypeNull; 
    r.quadlinenum = -1; 
    r.bytesize = 0; 
    r.params = NULL; 
    r.vars = NULL; 
    r.next = NULL; 
    return r; 
}

void SetFTE(FTE* fte, char* moduleid, TableType returntype, int quadline){
    printf("setting fte\n"); 
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
    fte->bytesize = totalBytes; 
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

int __is_func_table_empty(FuncTable* ft){
    return (ft->__current_size == 0 ? 1 : 0); 
}

void __print_func_table(FuncTable* ft){
    if(ft->isEmpty){
        printf("[empty]\n"); 
        return; 
    }
    FTE* iter; 
    for(int n = 0; n<ft->size; n++){
        iter = (ft->__dict+n);
        while(iter->isSet){
            printf("[Func ID : %s |Return Type: %s |Bytesize: %d | Quadruple Line: %d]\n", iter->moduleid, __enumToString(iter->returntype), iter->bytesize, iter->quadlinenum);   
            printf("----------------------------------------------------------------------\n"); 
            printf("------------------------------ Params --------------------------------\n"); 
            iter->params->print(iter->params); 
            printf("------------------------------- Vars ---------------------------------\n"); 
            iter->vars->print(iter->vars); 
            iter = iter->next; 
        }
    }
    
}

int __add_to_func_table(FuncTable* table, char* funcid, TableType returntype, int quaddir){
    int hash = __hash3(funcid,table->size); 
    FTE* iter = (table->__dict+hash); 
    while(iter->isSet){
        if(strcmp(funcid, iter->moduleid) == 0)
            return 0; 
        iter = iter->next; 
    }
    SetFTE(iter, funcid, returntype, quaddir);  
    table->__current_size++; 
    return 1; 
}

void DestroyFuncTable(FuncTable* table){
     FTE* iter = (table->__dict);
     for(int n = 0; n<table->size; n++){
         if((iter+n)->isSet){
             DestroyVarTable((iter+n)->params); 
             DestroyVarTable((iter+n)->vars); 
             DestroyFTE((iter+n)->next); 
         }
     }
     free(table->__dict); 
}

FuncTable NewFuncTable(int size){
    FuncTable ft; 
    ft.__dict = calloc(size, sizeof(FTE)); 
    for(int n = 0; n<size; n++)
        *(ft.__dict) = NewFTE(); 
    ft.size = size; 
    ft.__current_size = 0; 
    ft.isEmpty = &__is_func_table_empty; 
    ft.print = &__print_func_table;  
    ft.add = &__add_to_func_table; 
    //update
    //lookup
    return ft; 
}
