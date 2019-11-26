#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <jedi.h> 

VarTable globals; 

void Test1(VarTable* t){
    char* id = calloc(7, sizeof(char)); 
    strcpy(id, "Carlos"); 
    DIM* dim = calloc(1, sizeof(DIM)); *dim = NewDIM(); 
    if(!t->add(t, id, 5000, TableInt, dim))
        DestroyDIM(dim); 
    free(id); 
}

void Test2(){
    DestroyVarTable(&globals); 
}



int main(){
    globals = NewVarTable(15); 
    Test1(&globals); 
    Test2(); 
    return 0; 
}
