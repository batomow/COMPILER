#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 

void test(VarTable* vt){
    DIM dim1 = NewDIM(); SetDIM(&dim1, 2, 1); 
    DIM dim2 = NewDIM(); SetDIM(&dim2, 3, 1);
    DIM dim3 = NewDIM(); SetDIM(&dim3, 4, 1); 
    AddDIM(&dim1, &dim2); 
    AddDIM(&dim1, &dim3); 
    vt->add(vt, "Carlos", TableInt, 5000,  dim1); 
    vt->add(vt, "Ian", TableInt, 5001, dim2); 
}

void test2(VarTable* vt){
    vt->remove(vt, "Carlos"); 
    vt->remove(vt, "Ian"); 
}


int main(){ 
    return 0; 
}
