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
	
}
void visualize(StackArrayList s){
	
}
