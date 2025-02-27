#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 5  // Maximum size of the queue
// Structure to hold details of each call
typedef struct {
    int callID;
    char customerName[50];
} Call;

// Structure to represent the queue
typedef struct {
    Call calls[MAX_SIZE];  // Array to hold calls in the queue
    int front, rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(Queue *q) {
    return (q->front == -1);
}

// Function to check if the queue is full
int isFull(Queue *q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

// Function to enqueue a call into the queue
void enqueue(Queue *q, const char* customerName, int *callIDCounter) {
    if (isFull(q)) {
        printf("The queue is full. Cannot add more calls.\n");
        return;
    }   
    // If the queue is empty, both front and rear are set to 0
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        // Circularly increment rear index
        q->rear = (q->rear + 1) % MAX_SIZE;
    }
    // Generate a new call ID
    int newCallID = (*callIDCounter)++;
    // Add the call to the queue
    q->calls[q->rear].callID = newCallID;
    strcpy(q->calls[q->rear].customerName, customerName);

    printf("Call with ID %d for customer '%s' added to the queue.\n", newCallID, customerName);
}
// Function to dequeue a call from the queue
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty. No call to dequeue.\n");
        return;
    }
    // Dequeue the call and print the details
    printf("Serving the call with ID %d for customer '%s'.\n", q->calls[q->front].callID, q->calls[q->front].customerName);

    // If there is only one element in the queue, reset front and rear to -1
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        // Circularly increment the front index
        q->front = (q->front + 1) % MAX_SIZE;
    }
}

// Function to display the current state of the queue
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("The queue is empty.\n");
        return;
    }
    printf("Current Queue: \n");
    int i = q->front;
    while (i != q->rear) {
        printf("Call ID: %d, Customer: '%s'\n", q->calls[i].callID, q->calls[i].customerName);
        i = (i + 1) % MAX_SIZE;
    }
    // Print the last element
    printf("Call ID: %d, Customer: '%s'\n", q->calls[q->rear].callID, q->calls[q->rear].customerName);
}

// Main function
int main() {
    int choice;
    int callIDCounter = 1;  // Initialize the call ID counter
    char customerName[50];
    Queue q;
    initQueue(&q);  // Initialize the queue
    do {
        // Displaying menu options
        printf("\nCall Center Queue System\n");
        printf("1. Enqueue (Add Call)\n");
        printf("2. Dequeue (Serve Call)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character left by scanf
        switch (choice) {
            case 1:
                // Enqueue operation
                printf("Enter Customer Name: ");
                fgets(customerName, sizeof(customerName), stdin);
                customerName[strcspn(customerName, "\n")] = '\0';  // Remove trailing newline character
                enqueue(&q, customerName, &callIDCounter);
                break;
            case 2:
                // Dequeue operation
                dequeue(&q);
                break;
            case 3:
                // Display the queue
                displayQueue(&q);
                break;


            case 4:
                // Exit the program
                printf("Exiting the Call Center Queue System. Goodbye!\n");
                break;
            default:
                // Handle invalid choice
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);  // Loop until the user chooses to exit
    return 0;
}
