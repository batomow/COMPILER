#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include "jedi.h"


int isEmpty(Stack* stack){
	return stack->size == 0; 
}

void __push_alloc(Stack* stack){
	stack->size++; 
	if (stack->size > stack->__total_size){
		stack->__total_size *= 2;
		stack->__stack=realloc(stack->__stack, stack->__total_size*sizeof(Var));
	}
}

void push(Stack* stack, Var item){
	__push_alloc(stack); 
	stack->__stack[stack->size - 1] = item;
}	


Var peek(Stack* stack){
	Var top; 
	if(!isEmpty(stack)){
		top = stack->__stack[stack->size-1]; 
	}
	return top;
}	

void pop(Stack* stack){
	if (!isEmpty(stack)){	
		stack->size--; 
		if (stack->size < stack->__total_size/2){
			stack->__total_size /= 2; 
			stack->__stack=realloc(stack->__stack, stack->__total_size*sizeof(Var)); 
		}
	}
}

void __guard(Stack* stack, int position){
	if (position > stack->size-1 || position < 0){
		fprintf(stderr, "That position (%d) is outside the bounds of the structure [0,%d]\nexit code 117\n", position, stack->size-1); 
		exit(117);//should destroy stack? 
	}
}

void insert(Stack* stack, Var item, int position){
	if (isEmpty(stack)){
		push(stack, item); 
		return; 
	}
	push(stack, item); 
	__guard(stack, position); 
	Var aux = peek(stack); 
	for(int n = stack->size-1; n>position; n--){
		stack->__stack[n] = stack->__stack[n-1];	
	}
	stack->__stack[position] = aux; 
}


void print_stack(Stack* stack){
	if (isEmpty(stack)){
		printf("Stack []\n"); 
		return; 
	}
	printf("Stack -"); 
	for(int n = 0; n< stack->size; n++){
		Var item  = stack->__stack[n]; 
        char* aux = VarToString(item); 
        printf("[%s]", aux); 
       	free(aux); 
	}
	printf("->\n"); 
}

Var accessElement(Stack* stack, int position){
    __guard(stack, position); 
    Var result = stack->__stack[position]; 
    return result; 
}

Var extract(Stack* stack, int position){
	__guard(stack, position); 
	Var result = stack->__stack[position]; 
	for(int n = position; n<stack->size-1; n++){	
		stack->__stack[n] = stack->__stack[n+1]; 
	}
	pop(stack); 	
	return result; 
}

Stack NewStack(DataType type, int set_size)
{
	Stack new_stack;
	new_stack.__stack= malloc(sizeof(Var)*set_size); 
	new_stack.__type = type;
	new_stack.__total_size = set_size;
	new_stack.size = 0; 
	new_stack.isEmpty = &isEmpty;
	new_stack.print = &print_stack; 
	return new_stack;
}


Stack NewStackFromArray(Var* array, int size){
	Stack new_stack = NewStack(TypeInt, size); 
	for(int n = 0; n<size; n++){
		push(&new_stack, array[n]); 
	}
	return new_stack; 
}

void DestroyStack(Stack* stack){
	free(stack->__stack); 
	stack->size = 0; 
	stack->__total_size = 0; 
}
