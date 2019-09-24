#include <stdio.h> 
#include <stdlib.h> 
#include <mylib.h> 
 

int main(){ 
	Stack s1 = NewStack(TypeInt, 3); 
	Var a = NewVarI(10), b = NewVarS("Hello"), c = NewVarF(10.2); 
	s1.push(&s1, a); 
	s1.push(&s1, b);
	s1.push(&s1, c); 
	s1.print(&s1); 
	DestroyStack(&s1); 
	return 0; 
}
