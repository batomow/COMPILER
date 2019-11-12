#include <stdio.h> 
#include <stdlib.h> 
#include "mylib.h" 

unsigned long __hash(char* word, int size){
    unsigned long hash = 5391; 
    int c; 
    while((c = *word++)){
        hash = ((hash<<5)+hash) + c; 
    }
    return hash % size; 
}
 

