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

void test3(Stack* st){
    *st = NewStack(TypeInt, 10); 
    push(st, NewVarI(1)); 
    push(st, NewVarI(2)); 
    push(st, NewVarI(3)); 
    push(st, NewVarI(4)); 
    push(st, NewVarI(5)); 
    push(st, NewVarI(6)); 
    push(st, NewVarI(7)); 
}

void test5(Stack* st){
    *st = NewStack(TypeInt, 10); 
}

void test4(Stack* st){
    DestroyStack(st); 
}

int main(){ 
    Stack st; 
    int a = 0; 
    while(a != '0'){
        for(int n = 0; n<1000; n++){
            test5(&st);
            test4(&st); 
        }
        a = getchar();
    }
    return 0; 
}
