// Write a C program to find distance between two nodes in binary tree
#include <stdio.h>
#include <stdlib.h>

// Node structure for the binary tree
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to find the Lowest Common Ancestor (LCA)
struct Node *findLCA(struct Node *root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data == n1 || root->data == n2) return root;

    struct Node *leftLCA = findLCA(root->left, n1, n2);
    struct Node *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA) return root;

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Function to find the distance from root to a given node
int findDistance(struct Node *root, int key, int distance) {
    if (root == NULL) return -1;

    if (root->data == key) return distance;

    int leftDist = findDistance(root->left, key, distance + 1);
    if (leftDist != -1) return leftDist;

    return findDistance(root->right, key, distance + 1);
}

// Function to find the distance between two nodes in a binary tree
int findDistanceBetweenNodes(struct Node *root, int n1, int n2) {
    struct Node *lca = findLCA(root, n1, n2);
    if (lca == NULL) return -1;  // If LCA is NULL, nodes are not present

    int d1 = findDistance(lca, n1, 0);
    int d2 = findDistance(lca, n2, 0);

    return d1 + d2;
}

int main() {
    // Creating a sample binary tree
    struct Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);

    int n1, n2;
    printf("Enter two node values to find the distance: ");
    scanf("%d %d", &n1, &n2);

    int distance = findDistanceBetweenNodes(root, n1, n2);
    if (distance != -1)
        printf("Distance between node %d and node %d is: %d\n", n1, n2, distance);
    else
        printf("One or both nodes are not present in the tree.\n");

    return 0;
}
