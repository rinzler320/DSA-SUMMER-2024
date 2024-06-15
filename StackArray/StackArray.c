#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top=-1;
}

StackArrayList createStack(){
	StackArrayList s;
	initStack(&s);
	return s;
}

bool stack_push(StackArrayList *s, int elem){
	if(s->top == MAX-1){
		return false;
	}
	s->top++;
	s->data[s->top]=elem;
	return true;
}

bool stack_pop(StackArrayList *s){
	if(s->top == -1){
		return false;
	}
	s->top--;
	return true;
}
int stack_peek(StackArrayList s){
	return s.data[s.top];
}

bool isEmpty(StackArrayList s){
	return (s.top == -1)? true: false;
}

bool isFull(StackArrayList s){
	return (s.top == MAX-1)? true: false;
}

void display(StackArrayList s){
	if(isEmpty(s)){
		printf("Stack is empty.\n");
	}else{
		printf("Stack elements:\n");
		int i;
		for(i=0;i<=s.top;i++){
			printf("%d", s.data[i]);
		}
	}
	printf("\n");
}
void visualize(StackArrayList s){
	printf("Visualizing the stack:\n");
	printf("TOP\n");
	int i;
	for(i=s.top;i>=0;i--){
		printf("| %d |\n", s.data[i]);
	}
	printf("BOTTOM\n");
}

StackArrayList getEvenNumbers(StackArrayList *s){
	StackArrayList evenStack = createStack();
	StackArrayList tempStack = createStack();
	
	while(!isEmpty(*s)){
		int topElem=stack_peek(*s);
		stack_pop(s);
		if(topElem%2==0){
			stack_push(&evenStack, topElem);
		}else{
			stack_push(&tempStack, topElem);
		}
	}
	while(!isEmpty(tempStack)){
		int topElem=stack_peek(tempStack);
		stack_pop(&tempStack);
		stack_push(s, topElem);
	}
	
	return evenStack;
}
