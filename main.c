#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 

int main(){
    FuncTable ft = NewFuncTable(10); 
    ft.print(&ft); 
    if(ft.add(&ft, "sumapatito", TableInt, 0))
        ft.print(&ft); 
    printf("current size: %d\n", ft.__current_size);    
    if(!ft.isEmpty)
        printf("its not empty\n"); 
    DestroyFuncTable(&ft); 
    return 0; 
}
