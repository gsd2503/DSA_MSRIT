// Write a C program to remove duplicate elements from a soreted linked list

#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Global head of the linked list
struct Node *head = NULL;

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a new node to the linked list
void appendNode(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates() {
    struct Node *current = head;

    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            struct Node *duplicate = current->next;
            current->next = duplicate->next;
            free(duplicate);
        } else {
            current = current->next;
        }
    }
}

// Function to display the linked list
void displayList() {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Append Node\n");
        printf("2. Remove Duplicates\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to append: ");
                scanf("%d", &data);
                appendNode(data);
                break;

            case 2:
                removeDuplicates();
                printf("Duplicates removed from the list.\n");
                break;

            case 3:
                printf("Linked List: ");
                displayList();
                break;

            case 4:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
