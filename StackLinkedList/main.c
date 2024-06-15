#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"


int main(int argc, char *argv[]) {
    StackLinkedList s = createStack();
    
    for(int i = 0; i < 10; i++){
        stack_push(&s, i);
    }

    printf("Original Stack:\n");
    display(s);
    
    StackLinkedList evenStack = getEvenNumbers(&s);
    printf("Even numbers stack: ");
    visualize(evenStack);
    
    printf("Original stack after removing even numbers: ");
    visualize(s);

    return 0;
}
