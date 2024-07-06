#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BST.h"

NodePtr createNode(Product item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode != NULL) {
        newNode->item = item;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}


NodePtr insert(NodePtr root, Product item) {
    if (root == NULL) {
        return createNode(item);
    }
    if (strcmp(item.prodName, root->item.prodName) < 0) {
        root->left = insert(root->left, item);
    } else if (strcmp(item.prodName, root->item.prodName) > 0) {
        root->right = insert(root->right, item);
    }
    return root;
}


NodePtr findMin(NodePtr root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


NodePtr deleteNode(NodePtr root, char *prodName) {
    if (root == NULL) return root;

    if (strcmp(prodName, root->item.prodName) < 0) {
        root->left = deleteNode(root->left, prodName);
    } else if (strcmp(prodName, root->item.prodName) > 0) {
        root->right = deleteNode(root->right, prodName);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor
        NodePtr temp = findMin(root->right);
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item.prodName);
    }
    return root;
}


void inorder(NodePtr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Product: %s, Price: %.2f, Quantity: %d, Expiry: %d/%d/%d\n", root->item.prodName, root->item.prodPrice, root->item.prodQty, root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
        inorder(root->right);
    }
}


void preorder(NodePtr root) {
    if (root != NULL) {
        printf("Product: %s, Price: %.2f, Quantity: %d, Expiry: %d/%d/%d\n", root->item.prodName, root->item.prodPrice, root->item.prodQty, root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(NodePtr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("Product: %s, Price: %.2f, Quantity: %d, Expiry: %d/%d/%d\n", root->item.prodName, root->item.prodPrice, root->item.prodQty, root->item.expDate.day, root->item.expDate.month, root->item.expDate.year);
    }
}


void breadthFirst(NodePtr root) {
    if (root == NULL) return;

    NodePtr queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        NodePtr current = queue[front++];
        printf("Product: %s, Price: %.2f, Quantity: %d, Expiry: %d/%d/%d\n", current->item.prodName, current->item.prodPrice, current->item.prodQty, current->item.expDate.day, current->item.expDate.month, current->item.expDate.year);

        if (current->left != NULL) queue[rear++] = current->left;
        if (current->right != NULL) queue[rear++] = current->right;
    }
}


Product getUserInput() {
    Product p;
    printf("Enter product name: ");
    scanf("%s", p.prodName);
    printf("Enter product price: ");
    scanf("%f", &p.prodPrice);
    printf("Enter product quantity: ");
    scanf("%d", &p.prodQty);
    printf("Enter expiry date (day month year): ");
    scanf("%d %d %d", &p.expDate.day, &p.expDate.month, &p.expDate.year);
    printf("\n");
    return p;
}


