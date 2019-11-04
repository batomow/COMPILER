#include <stdio.h> 
#include <stdlib.h> 
#include <jedi.h> 
#include <string.h> 


char* showBitsLetter(char letter){
    char* result = (char*)calloc(sizeof(char), 9); 
    int counter = 0; 
    for(int i = 7; i >=0; i--){
       result[counter] = ((1 << i) & letter) ? '1' : '0';
       counter++; 
    }
    result[8] = '\0'; 
    return result; 
}

char* showBitsWord(char* word, int size){
    char* result = (char*)calloc(sizeof(char*), size); 
    for(int n = 0; n<size; n++){
        strcat(result, showBitsLetter(word[n])); 
        strcat(result, " "); 
    }
    return result; 
}
int main(){ 
    Dictionary test = NewDictionary(10);
    add(&test, NewVarS("Carlos"), NewVarS("Miranda")); 
    add(&test, NewVarS("Cristhel"), NewVarS("Rubio")); 
    add(&test, NewVarI(8), NewVarS("Juan")); 
    KeyValuePair maria9 = NewKeyValuePair(NewVarI(9), NewVarS("Maria")); 
    add_pair(&test, maria9); 
    test.print(&test); 
    Var lastname = lookup(&test, NewVarS("Cristhel")); 
    printf("%s\n", lastname.data.sVal); 
    return 0; 
}
