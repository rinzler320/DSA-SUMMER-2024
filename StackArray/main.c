#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"


int main(int argc, char *argv[]) {
	StackArrayList s=createStack();
	
	int i;
	for(i=0;i<10;i++){
		stack_push(&s, i);
	}

//	stack_pop(&s);
//	stack_peek(s);
	
	printf("Original Stack:\n");
	display(s);
	
	StackArrayList evenStack = getEvenNumbers(&s);
	printf("Even numbers stack: ");
	visualize(evenStack);
	
	printf("Original stack after removing even numbers: ");
	visualize(s);

	return 0;
}
