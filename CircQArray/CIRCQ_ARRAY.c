#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "CIRCQ_ARRAY.h"

void initQueue(circularQ *cQ){
	cQ->front=1;
	cQ->rear=0;
}

void Enqueue(circularQ *cQ, int data){
	cQ->rear=(cQ->rear+1)%MAX;
	cQ->data[cQ->rear]=data;
}

void Dequeue(circularQ *cQ){
	cQ->front=(cQ->front+1)%MAX;
}

int Front(circularQ cQ){
	return cQ.data[cQ.front];
}

int Rear(circularQ cQ){
	return cQ.data[cQ.rear];
}

bool isEmpty(circularQ cQ){
	if((cQ.rear+1)%MAX==cQ.front){
		return true;
	}else{
		return false;
	}
}

bool isFull(circularQ cQ){
	if((cQ.rear+2)%MAX==cQ.front){
		return true;
	}else{
		return false;
	}
}

void display(circularQ cQ){
	printf("Queue elements:\n");
	int i;
	for(i=cQ.front;i!=cQ.rear;i=(i+1)%MAX){
		printf("%d ", cQ.data[i]);
	}
	printf("%d\n", cQ.data[cQ.rear]);
}
