#include <stdlib.h> 
#include <stdio.h> 
#include "mylib.h"
#define MOD 2971215073
#define POW 127


unsigned int __hash(Var value, int size){
	
}	
unsigned int __hash_raw(DataType, void* value, int size); 


void add(Dictionary* dict, Var key, Var value); 
void add_raw(Dictionary* dict, void* key, void* value); 
void add_pair(Dictionary* dict, KeyValuePair kvp); 
int has_key(Dictionary* dict, Var key); 
var* get_keys(Dictionary* dict); 
Var* get_values(Dictionary* dict); 
Var lookup(Dictionary* dict, Var key); 

