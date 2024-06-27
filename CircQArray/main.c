#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CIRCQ_ARRAY.h"


int main(int argc, char *argv[]) {
	circularQ cQ;
	initQueue(&cQ);
	int i;
//	Enqueue(&cQ, 1);
//	Enqueue(&cQ, 2);
//	Enqueue(&cQ, 3);
//	Enqueue(&cQ, 4);
//	Enqueue(&cQ, 5);
	for(i=0;i<=MAX;i++){
		Enqueue(&cQ, i);
	}
	
	Dequeue(&cQ);
	Dequeue(&cQ);
	display(cQ);
	return 0;
}
