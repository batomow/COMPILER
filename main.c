#include <stdio.h> 
#include <stdlib.h> 
#include <mylib.h> 
 

int main(){ 
	Stack s1 = NewStack(TypeInt, 3); 
	Var a = NewVarI(10), b = NewVarS("Hello"), c = NewVarF(10.2), d = NewVarS("Inserted Val"); 
	push(&s1, a); 
	push(&s1, b);
	push(&s1, c); 
	s1.print(&s1); 
	insert(&s1, d, 0); 
	s1.print(&s1); 
	Var item = extract(&s1, 0); 
	s1.print(&s1); 
	printf("returned value: %s\n", item.data.sVal); 
	Var item2 = extract(&s1, 1); 
	s1.print(&s1); 
	printf("returned value: %s\n", item2.data.sVal); 
	DestroyStack(&s1); 
	return 0; 
}
