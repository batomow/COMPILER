#include <string.h> 
#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include "mylib.h"


int is_empty(Stack stack){
	return stack.size == 0; 
}

void __push_alloc(Stack* stack){
	stack->size++; 
	if (stack->size > stack->__total_size){
		stack->__total_size *= 2;
		stack->__stack=realloc(stack->__stack, stack->__total_size*sizeof(Var));
	}
}

void push_raw(Stack* stack, void* item){//Advanced Feature:might truncate if not typed correctly
	Var new_item; 
	switch(stack->__type){
		case TypeInt: new_item.data.iVal = *(int*) item; break; 
		case TypeFloat: new_item.data.fVal = *(float*)item; break; 
		case TypeDouble: new_item.data.dVal = *(double*)item; break;
		case TypeString: new_item.data.sVal = *(char**)item; break; 
		case TypeChar: new_item.data.cVal = *(char*)item; break; 
	}
	new_item.type = stack->__type; 	
	__push_alloc(stack); 
	stack->__stack[stack->size - 1] = new_item; 
}

void push(Stack* stack, Var item){
	__push_alloc(stack); 
	stack->__stack[stack->size - 1] = item;
}	


Var peek(Stack* stack){
	Var top; 
	if(!is_empty(*stack)){
		top = stack->__stack[stack->size-1]; 
	}
	return top;
}	

void pop(Stack* stack){
	if (!is_empty(*stack)){	
		stack->size--; 
		if (stack->size < stack->__total_size/2){
			stack->__total_size /= 2; 
			stack->__stack=realloc(stack->__stack, stack->__total_size*sizeof(Var)); 
		}
	}
}

void __insert_guard(Stack* stack, int position){
	if (position > stack->size || position < 0){
		fprintf(stderr, "That position is outside the bounds of the structure"); 
		exit(117);
	}
}
void __insert_swap(Stack* stack, int position){
	Var aux = peek(stack); 
	for(int n = stack->size; n>=position; n--){
		stack->__stack[n] = stack->__stack[n-1];	
	}
	stack->__stack[position] = aux; 
}

void insert_raw(Stack* stack, void* item, int position){
	__insert_guard(stack, position);
	push_raw(stack, item); 
	__insert_swap(stack, position); 
}

void insert(Stack* stack, Var item, int position){
	__insert_guard(stack, position); 
	push(stack, item); 
	__insert_swap(stack, position); 
}


void print_stack(Stack* stack){
	for(int n = 0; n< stack->size; n++){
		Var item  = stack->__stack[n]; 
		switch(item.type){
			case TypeInt: 
				printf("[%d]", item.data.iVal); 
				break; 
			case TypeFloat: 
				printf("[%0.4f]", item.data.fVal); 
				break; 
			case TypeDouble: 
				printf("[%0.4f]", item.data.dVal); 
				break; 
			case TypeString: 
				printf("[%s]", item.data.sVal); 
				break; 
			case TypeChar:
				printf("[%c]", item.data.cVal); 
				break; 
		}
	}
	printf("\n"); 
}

Stack NewStack(DataType type, int set_size)
{
	Stack new_stack;
	new_stack.__stack= calloc(set_size, sizeof(Var));
	new_stack.__type = type;
	new_stack.__total_size = set_size;
	new_stack.size = 0; 
	new_stack.is_empty = &is_empty;
	new_stack.push_raw = &push_raw; 
	new_stack.push = &push;
	new_stack.pop = &pop; 
	new_stack.peek = &peek; 
	new_stack.print = &print_stack; 
	new_stack.insert_raw = &insert_raw;
	new_stack.insert = &insert; 
	return new_stack;
}

void DestroyStack(Stack* stack){
	for(int n = 0; n < stack->size; n++){
		pop(stack); 
	}
	free(stack->__stack); 
}
