#include <stdio.h>
#include <stdlib.h>
#include "FCFS_ARRAYQ.h"


int main(int argc, char *argv[]) {
	int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    Queue* queue = createQueue(n);
    int i;
    for (i = 0; i < n; ++i) {
        Process proc;
        proc.id = 'A' + i;
        printf("Enter burst time for process %c: ", proc.id);
        scanf("%d", &proc.bt);
        printf("Enter arrival time for process %c: ", proc.id);
        scanf("%d", &proc.at);
        printf("\n");
        enqueue(queue, proc);
    }

    printf("\nFirst Come First Serve - CPU Scheduling\n\n");
    printf("INPUT PROCESS\n");
    printf("Total Number: %d\n\n", n);

    calculateTimes(queue, n);

    if (queue) {
        free(queue->data);
        free(queue);
    }
    return 0;
}
