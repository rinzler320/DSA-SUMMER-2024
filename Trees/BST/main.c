#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"


int main() {
    NodePtr root = NULL;
    Product p1 = {"Milk", 2.50, 10, {12, 12, 2023}};
    Product p2 = {"Bread", 1.20, 15, {15, 8, 2024}};
    Product p3 = {"Butter", 3.75, 5, {20, 11, 2024}};
    Product p4 = {"Cheese", 4.50, 20, {25, 9, 2023}};
    
    root = insert(root, p1);
    root = insert(root, p2);
    root = insert(root, p3);
    root = insert(root, p4);

    printf("Inorder Traversal:\n");
    inorder(root);

    printf("\nPreorder Traversal:\n");
    preorder(root);

    printf("\nPostorder Traversal:\n");
    postorder(root);

    printf("\nBreadth-First Traversal:\n");
    breadthFirst(root);

    printf("\nDeleting 'Bread':\n");
    root = deleteNode(root, "Bread");

//    printf("Inorder Traversal after deletion:\n");
//    inorder(root);
//
//    printf("\nPreorder Traversal after deletion:\n");
//    preorder(root);

    printf("\nPostorder Traversal after deletion:\n");
    postorder(root);

//    printf("\nBreadth-First Traversal after deletion:\n");
//    breadthFirst(root);

    // Add user input for new products or deletions
    char choice;
    do {
        printf("\nDo you want to add a new product (a) or delete an existing one (d)? (a/d): ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            Product newProduct = getUserInput();
            root = insert(root, newProduct);
        } else if (choice == 'd') {
            char delName[20];
            printf("Enter the name of the product to delete: ");
            scanf("%s", delName);
            root = deleteNode(root, delName);
        }

        printf("Inorder Traversal:\n");
        inorder(root);

        printf("\nPreorder Traversal:\n");
        preorder(root);

        printf("\nPostorder Traversal:\n");
        postorder(root);

        printf("\nBreadth-First Traversal:\n");
        breadthFirst(root);

        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}


