#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 


void test(VarTable* vt){
    DIM* dim1 = calloc(1, sizeof(DIM)); 
    DIM* dim2 = calloc(1, sizeof(DIM)); 
    DIM* dim3 = calloc(1, sizeof(DIM)); 
    *dim1 = NewDIM(); SetDIM(dim1, 2, 1); 
    *dim2 = NewDIM(); SetDIM(dim2, 3, 1); 
    *dim3 = NewDIM(); SetDIM(dim3, 4, 1); 
    AddDIM(dim1, dim2); 
    AddDIM(dim1, dim3); 
    vt->add(vt, "Carlos", TableInt, 5000, dim1); 
    vt->add(vt, "Ian", TableInt, 5001, dim2); 
    AddDIM(dim3, dim2); 
    vt->add(vt, "Cristhel", TableInt, 5002, dim3); 
    DIM* dim4 = calloc(1, sizeof(DIM)); 
    *dim4 = NewDIM(); SetDIM(dim4, 7, 1); 
    AddDIM(dim4, dim2); 
    vt->add(vt, "Nicolas", TableInt, 5003, dim4); 
    
}

int main(){
    VarTable vt = NewVarTable(10);
    test(&vt); 
    vt.print(&vt);
    char* id = "Nicolas"; 
    VTE res = vt.lookup(&vt, id); 
    res.isSet ? printf("found\n") : printf("Not found\n"); 
    char* aux = res.dim->toString(res.dim); 
    printf("%s's dim: %s\n",id, aux);
    free(aux); 
    printf("removing: %s\n", id); 
    vt.remove(&vt, id); 
    vt.print(&vt); 
    DestroyVarTable(&vt); 
    return 0; 
}
