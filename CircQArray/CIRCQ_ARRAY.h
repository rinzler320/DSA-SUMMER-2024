#ifndef CIRCQ_ARRAY
#define CIRCQ_ARRAY
#define MAX 10

typedef struct{
	int data[MAX];
	int front;
	int rear;
}circularQ;

void initQueue(circularQ *cQ);
void Enqueue(circularQ *cQ, int data);
void Dequeue(circularQ *cQ);
int Front(circularQ cQ);
int Rear(circularQ cQ);
bool isEmpty(circularQ cQ);
bool isFull(circularQ cQ);
void display(circularQ cQ);


#endif


