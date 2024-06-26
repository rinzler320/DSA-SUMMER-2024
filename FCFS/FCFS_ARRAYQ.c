#include <stdio.h>
#include <stdlib.h>
#include "FCFS_ARRAYQ.h"

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->data = (Process*)malloc(queue->capacity * sizeof(Process));
    if (!queue->data) {
        printf("Memory allocation error\n");
        free(queue);
        exit(EXIT_FAILURE);
    }
    return queue;
}

int isFull(Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(Queue* queue) {
    return (queue->size == 0);
}

void enqueue(Queue* queue, Process item) {
    if (isFull(queue)) {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size = queue->size + 1;
}

Process dequeue(Queue* queue) {
    Process item = {'\0', 0, 0, 0, 0, 0};
    if (isEmpty(queue)) {
        return item;
    }
    item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


void sortProcessesByArrival(Process* proc, int n) {
	int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (proc[j].at > proc[j + 1].at) {
                Process temp = proc[j];
                proc[j] = proc[j + 1];
                proc[j + 1] = temp;
            }
        }
    }
}

void calculateTimes(Queue* queue, int n) {
    int totalWT = 0, totalTT = 0;
    int currTime = 0;
    Process* proc = queue->data;


    sortProcessesByArrival(proc, n);


    int i;
	for (i = 0; i < n; i++) {
        if (currTime < proc[i].at) {
            currTime = proc[i].at;
        }
        proc[i].et = currTime + proc[i].bt;
        currTime = proc[i].et;

        proc[i].tt = proc[i].et - proc[i].at;
        proc[i].wt = proc[i].tt - proc[i].bt;

        totalWT += proc[i].wt;
        totalTT += proc[i].tt;
    }


    printf("PROCESS TABLE\n");
    printf("Process\tBT\tAT\tET\tWT\tTT\n");
    for (i = 0; i < n; ++i) {
        printf("%c\t%d\t%d\t%d\t%d\t%d\n", 
               proc[i].id, 
               proc[i].bt, 
               proc[i].at, 
               proc[i].et, 
               proc[i].wt, 
               proc[i].tt);
    }

    printf("TOTAL\t-\t-\t-\t%d\t%d\n", totalWT, totalTT);


    printf("\nOUTPUT INFORMATION\n");
    printf("WT Total : %d\n", totalWT);
    printf("WT Average : %.2f\n", (double)totalWT / n);
    printf("TT Total : %d\n", totalTT);
    printf("TT Average : %.2f\n", (double)totalTT / n);
}
