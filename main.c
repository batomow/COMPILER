#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 

int main(){
    FTE* fte = calloc(1, sizeof(FTE)); 
    *fte = NewFTE(); 
    SetFTE(fte, "FirstModule", TableNull, 0); 
    printf("the size of var is: %lu\n", sizeof(Var));  
    DIM* dim1 = calloc(1, sizeof(DIM)); *dim1 = NewDIM(); 
    DIM* dim2 = calloc(1, sizeof(DIM)); *dim2 = NewDIM();  
    SetDIM(dim1, 3, 1); 
    fte->params->add(fte->params, "Carlos", TypeFloat, 5000, dim1); 
    fte->vars->add(fte->vars, "Cristhel", TypeInt, 6001, dim2); 
    UpdateTotalSize(fte); 
    printf("size of params: %d\n", fte->size); 
    
    DestroyFTE(fte); 
    return 0; 
}
