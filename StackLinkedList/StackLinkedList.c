#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLinkedList.h"

void initStack(StackLinkedList *s){
    s->top = NULL;
}

StackLinkedList createStack(){
    StackLinkedList s;
    initStack(&s);
    return s;
}

bool stack_push(StackLinkedList *s, int elem){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return false;  // Allocation failed
    }
    newNode->data = elem;
    newNode->next = s->top;
    s->top = newNode;
    return true;
}

bool stack_pop(StackLinkedList *s){
    if (isEmpty(*s)) {
        return false;
    }
    Node* temp = s->top;
    s->top = s->top->next;
    free(temp);
    return true;
}

int stack_peek(StackLinkedList s){
    if (isEmpty(s)) {
        return -1;  // Or some other error value
    }
    return s.top->data;
}

bool isEmpty(StackLinkedList s){
    return s.top == NULL;
}

void display(StackLinkedList s){
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        Node* current = s.top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    }
    printf("\n");
}

void visualize(StackLinkedList s){
    printf("Visualizing the stack:\n");
    printf("TOP\n");
    Node* current = s.top;
    while (current != NULL) {
        printf("| %d |\n", current->data);
        current = current->next;
    }
    printf("BOTTOM\n");
}

StackLinkedList getEvenNumbers(StackLinkedList *s){
    StackLinkedList evenStack = createStack();
    StackLinkedList tempStack = createStack();
    
    while (!isEmpty(*s)) {
        int topElem = stack_peek(*s);
        stack_pop(s);
        if (topElem % 2 == 0) {
            stack_push(&evenStack, topElem);
        } else {
            stack_push(&tempStack, topElem);
        }
    }
    while (!isEmpty(tempStack)) {
        int topElem = stack_peek(tempStack);
        stack_pop(&tempStack);
        stack_push(s, topElem);
    }
    
    return evenStack;
}
