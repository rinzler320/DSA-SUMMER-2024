#ifndef FCFS_ARRAYQ
#define FCFS_ARRAYQ

typedef struct {
    char id;
    int bt; // Burst Time
    int at; // Arrival Time
    int et; // Exit Time
    int wt; // Waiting Time
    int tt; // Turnaround Time
} Process;

typedef struct {
    Process* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity);
int isFull(Queue* queue);
int isEmpty(Queue* queue);
void enqueue(Queue* queue, Process item);
Process dequeue(Queue* queue);
void sortProcessesByArrival(Process* proc, int n);
void calculateTimes(Queue* queue, int n);

#endif
