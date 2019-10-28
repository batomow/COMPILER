#include <stdlib.h> 
#include <stdio.h> 
#include "jedi.h"


/*unsigned int __hash(Var value, int size){
	
}	
unsigned int __hash_raw(DataType, void* value, int size); */


void add(Dictionary* dict, Var key, Var value); 
void add_raw(Dictionary* dict, void* key, void* value); 
void add_pair(Dictionary* dict, KeyValuePair kvp); 
int has_key(Dictionary* dict, Var key); 
Var* get_keys(Dictionary* dict); 
Var* get_values(Dictionary* dict); 
Var lookup(Dictionary* dict, Var key); 

KeyValuePair NewKeyValuePair(Var key, Var value){
    KeyValuePair newkvp; 
    newkvp.key = key; 
    newkvp.value = value; 
    return newkvp; 
}
