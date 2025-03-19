// Code given by sir
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

struct StackNode* root = NULL;

struct StackNode* newNode(int data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

void push(int data) {
    struct StackNode* stackNode = newNode(data);
    stackNode->next = root;
    root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop() {
    if (root == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct StackNode* temp = root;
    root = root->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek() {
    if (root == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return root->data;
}

void display() {
    if (root == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct StackNode* temp = root;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nStack Operations Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("%d popped from stack\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
