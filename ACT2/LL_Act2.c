#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int idNum;
    int age;
} info;

typedef struct Node {
    info data;
    struct Node* next;
} Node, *NodePtr;


void insertFront(NodePtr *head, info data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next = *head;
    *head = newNode;
}


void insertLast(NodePtr *head, info data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else {
        NodePtr temp;
        for (temp = *head; temp->next != NULL; temp = temp->next);
        temp->next = newNode;
    }
}


void insertAtPosition(NodePtr *head, info data, int position) {
    if (position == 0) {
        insertFront(head, data);
        return;
    }
    
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data=data;
    newNode->next = NULL;

    NodePtr temp = *head;
    int i;
    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


void deleteFront(NodePtr *head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    NodePtr temp = *head;
    *head = (*head)->next;
    free(temp);
}


void deleteLast(NodePtr *head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    NodePtr temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


void deleteAtPosition(NodePtr *head, int position) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (position == 0) {
        NodePtr temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    NodePtr temp = *head;
    int i;
    for (i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    NodePtr nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}


void updateAtPosition(NodePtr head, info data, int position) {
    NodePtr temp = head;
    int i;
    for (i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    temp->data=data;
}


void printList(NodePtr head) {
	NodePtr temp;
    for (temp = head; temp != NULL; temp = temp->next) {
        printf("Name: %s, ID: %d, Age: %d\n", temp->data.name, temp->data.idNum, temp->data.age);
    }
}

int main() {
    NodePtr head = NULL;
    info data;
    char choice;
    char insertChoice;
	int position;
	
    do {
        printf("Enter name: ");
        scanf("%s", data.name);
        printf("Enter ID: ");
        scanf("%d", &data.idNum);
        printf("Enter age: ");
        scanf("%d", &data.age);

        printf("Insert at front, last, or specific position? (f/l/p): ");
        scanf(" %c", &insertChoice);
        
        if (insertChoice == 'f' || insertChoice == 'F') {
            insertFront(&head, data);
        } else if (insertChoice == 'l' || insertChoice == 'L') {
            insertLast(&head, data);
        } else if (insertChoice == 'p' || insertChoice == 'P') {
            printf("Enter position: ");
            scanf("%d", &position);
            insertAtPosition(&head, data, position);
        } else {
            printf("Invalid choice. Node not inserted.\n");
        }

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    do {
        printf("\nOptions: \n");
        printf("1. Delete front\n");
        printf("2. Delete last\n");
        printf("3. Delete at position\n");
        printf("4. Update at position\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                deleteFront(&head);
                break;
            case '2':
                deleteLast(&head);
                break;
            case '3':
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case '4':
                printf("Enter position to update: ");
                scanf("%d", &position);
                printf("Enter new name: ");
                scanf("%s", data.name);
                printf("Enter new ID: ");
                scanf("%d", &data.idNum);
                printf("Enter new age: ");
                scanf("%d", &data.age);
                updateAtPosition(head, data, position);
                break;
            case '5':
                printList(head);
                break;
            case '6':
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != '6');

    return 0;
}
