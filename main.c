#include <stdio.h> 
#include <stdlib.h> 
#include <mylib.h> 
#include <string.h> 

/*int testhash(Var key, int size){
	int hash = 0; 
	switch(key.type){
		
	}
	return hash; 
}*/

int main(){ 
	Var items[] = {NewVarI(11), NewVarS("Carlos"), NewVarC('D'), NewVarF(10.2)};
	Stack s1 = NewStackFromArray(items, 4); 
	s1.print(&s1); 

	int numitems[] = {1, 2, 3, 4, 5}; 
	Var* items2 = NewVarArrayI(numitems, 5); 

	Stack s2 = NewStackFromArrayRaw(TypeInt, numitems, 5); 
	s2.print(&s2); 

	Stack s3 = NewStackFromArray(items2, 5); 
	s3.print(&s3); 

	
	return 0; 
}
