#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 


int main(){
    OPDUM opdum1 = NewOPDUM("a", 5000, 0); 
    OPDUM opdum2 = NewOPDUM("b", 5001, 0); 
    OPDUM result = NewOPDUM("t1", 6000, 0); 
    QUAD quad = NewQUAD(SUM, opdum1, opdum2, result); 
    char* aux = QUADToStringHuman(quad);
    printf("%s\n", aux); 
    free(aux); 
    aux = QUADToStringMachine(quad); 
    printf("%s\n", aux); 
    free(aux); 
    return 0; 
}
