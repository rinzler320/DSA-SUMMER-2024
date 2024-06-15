#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} StackLinkedList;

void initStack(StackLinkedList *s);
StackLinkedList createStack();

bool stack_push(StackLinkedList *s, int elem);
bool stack_pop(StackLinkedList *s);
int stack_peek(StackLinkedList s);
bool isEmpty(StackLinkedList s);

void display(StackLinkedList s);
void visualize(StackLinkedList s);

// Function to get all even numbers and return as a new stack, 
//removing them from the old stack
StackLinkedList getEvenNumbers(StackLinkedList *s);
#endif
