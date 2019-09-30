#include <stdio.h> 
#include <stdlib.h> 
#include <mylib.h> 
 

int main(){ 
	Queue q1 = NewQueue(TypeInt, 4); 	
	DestroyQueue(&q1); 
	return 0; 
}
