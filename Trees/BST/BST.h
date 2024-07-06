#ifndef BST_H_
#define BST_H_

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[20];
    float prodPrice;
    int prodQty;
    Date expDate;
} Product;

typedef struct node {
    Product item;
    struct node *left, *right;
} NodeType, *NodePtr;

// Function prototypes
NodePtr createNode(Product item);
NodePtr insert(NodePtr root, Product item);
NodePtr findMin(NodePtr root);
NodePtr deleteNode(NodePtr root, char *prodName);
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void breadthFirst(NodePtr root);
Product getUserInput();

#endif

