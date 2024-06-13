#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList s=createStack();
	
	stack_push(&s, 1);
	stack_push(&s, 2);
	stack_push(&s, 3);
	stack_push(&s, 4);
	stack_push(&s, 5);
	stack_push(&s, 6);
	stack_push(&s, 7);
	stack_push(&s, 8);
	stack_push(&s, 9);
	stack_push(&s, 10);
	
	stack_pop(&s);
	stack_peek(s);
	
	printf("Original Stack:\n");
	display(s);
	
	
	visualize(s);
	getEvenStack();
	return 0;
}
