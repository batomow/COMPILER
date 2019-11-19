#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include "jedi.h"

void __reverse(Stack* src, Stack* target){
	Var aux; 
	while(!src->isEmpty(src)){
		aux = peek(src); 
		pop(src); 
		push(target, aux); 
	}
}

void popBack(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	if (back->isEmpty(back) && !front->isEmpty(front)){
		__reverse(front, back); 
		pop(back); 
	}else{
        pop(back); 
    }
}
void popFront(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	if (!back->isEmpty(back) && front->isEmpty(front)){
		__reverse(back, front); 
		pop(front); 
	}else{
        pop(front); 
    }
}
void pushBack(Queue* queue, Var item){
	Stack* back = &(queue->__back);
	push(back, item); 
} 	

void pushFront(Queue* queue, Var item){
	Stack* front = &(queue->__front); 
	push(front, item); 
}

Var peekFront(Queue* queue){
	Stack* front = &(queue->__front); 
	if(front->isEmpty(front)){
		Stack* back = &(queue->__back); 
		__reverse(back, front); 
	}
	Var result = peek(front); 
	return result; 
}	
Var peekBack(Queue* queue){
	Stack* back = &(queue->__back); 
	if(back->isEmpty(back)){
		Stack* front = &(queue->__front);
		__reverse(front, back); 
	}
	Var result = peek(back);
	return result; 
}
void print(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	printf("Queue -"); 
	for(int n = back->size-1; n>=0; n--){
		Var item = back->__stack[n]; 	
        char* aux = VarToString(item); 
        printf("[%s]", aux);
        free(aux); 
	}
	for(int n = 0; n<front->size; n++){
		Var item = front->__stack[n]; 	
        char* aux = VarToString(item); 
        printf("[%s]", aux); 
        free(aux); 
	}
	printf("->\n"); 
}

void __debug_print(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	printf("Queue Back -"); 
	for(int n = back->size-1; n>=0; n--){
		Var item = back->__stack[n]; 	
        char* aux = VarToString(item); 
        printf("[%s]", aux); 
        free(aux); 
	}printf("->\nQueue Front -"); 
	for(int n = 0; n<front->size; n++){
		Var item = front->__stack[n]; 	
        char* aux = VarToString(item); 
        printf("[%s]", aux); 
        free(aux); 
	}
	printf("->\n"); 	
}

int queue_isEmpty(Queue* queue){
	Stack *front = &(queue->__front), *back = &(queue->__back); 
	return (front->isEmpty(front) && back->isEmpty(back));
}

Queue NewQueue(DataType type, int size){ 
	int back_size = size/2; 
	int front_size = (size%2==0) ? (size/2) : (size/2 + 1); 
	Queue new_queue; 
	new_queue.__front = NewStack(type, front_size); 
	new_queue.__back = NewStack(type, back_size); 
	new_queue.print = &print; 
	new_queue.isEmpty = &queue_isEmpty;
	return new_queue; 
}

void DestroyQueue(Queue* queue){ 
	DestroyStack(&(queue->__back)); 
	DestroyStack(&(queue->__front)); 
}
