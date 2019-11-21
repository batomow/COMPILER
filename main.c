#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 


int test(FuncTable* ft){
    if(!ft->add(ft, "sumapatito", TableInt, 0))
        return 0; 
    
    if(!ft->add(ft, "restapatito", TableInt, 1))
        return 0; 
   
    if(!ft->add(ft, "divpatito", TableFloat, 2))
        return 0; 
    return 1; 
}

int test2(FuncTable* ft){
    DIM* dim1 = calloc(1, sizeof(DIM)); 
    *dim1 = NewDIM(); 
    SetDIM(dim1, 3, 1);  
    if(!ft->addVar(ft, "sumapatito", "Carlos", TableString, 5000, dim1)){
        DestroyDIM(dim1); 
        return 0; 
    }
    return 1; 
}

int test3(FuncTable* ft){
    DIM* dim1 = calloc(1, sizeof(DIM)); 
    *dim1 = NewDIM(); 
    if(!ft->addParam(ft, "sumapatito", "Ian", TableInt, 5001, dim1)){
        DestroyDIM(dim1); 
        return 0; 
    }
    return 1; 
}

int test4(FuncTable* ft){
    DIM* dim1 = calloc(1, sizeof(DIM)); 
    DIM* dim2 = calloc(1, sizeof(DIM)); 
    *dim1 = NewDIM();
    SetDIM(dim1, 2, 1); 
    *dim2 = NewDIM(); 
    SetDIM(dim2, 3, 1); 
    AddDIM(dim1, dim2); 
    if(!ft->addParam(ft, "sumapatito", "Cristhel", TableFloat, 5002, dim1)){
        DestroyDIM(dim1); 
        DestroyDIM(dim2); 
        return 0; 
    }
    DestroyDIM(dim2); 
    return 1; 
}

int main(){
    FuncTable ft = NewFuncTable(10); 
    test(&ft);
    test2(&ft);
    if(!test3(&ft))
        printf("failed!\n");  
    if(!test4(&ft))
        printf("failed!\n");  
    ft.print(&ft); 
    printf("sumapatito bytesize: %d\n", ft.updateSize(&ft, "sumapatito"));
    VTE* res2 = ft.lookupParam(&ft, "sumapatito", "Cristhel");  
    if(res2->isSet)
        printf("param found: %s | %d\n", res2->id, res2->dir); 
    VTE* res3 = ft.lookupVar(&ft, "sumapatito", "Carlos"); 
        printf("var found: %s | %d\n", res3->id, res3->dir); 
     
    DestroyFuncTable(&ft); 
    return 0; 
}
