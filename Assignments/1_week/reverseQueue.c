// Write a C program to reverse a Queue with out using loops
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

// Queue structure
struct Queue {
    int arr[MAX];
    int front;
    int rear;
} q;

// Function to initialize the queue
void initQueue() {
    q.front = -1;
    q.rear = -1;
}

// Function to check if the queue is empty
bool isEmpty() {
    return q.front == -1;
}

// Function to check if the queue is full
bool isFull() {
    return q.rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(int data) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }
    if (q.front == -1) {
        q.front = 0;
    }
    q.arr[++(q.rear)] = data;
    printf("Enqueued: %d\n", data);
}

// Function to dequeue an element
int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return -1;
    }
    int data = q.arr[q.front];
    if (q.front == q.rear) {
        q.front = q.rear = -1;  // Reset queue when empty
    } else {
        q.front++;
    }
    printf("Dequeued: %d\n", data);
    return data;
}

// Recursive function to reverse the queue
void reverseQueue() {
    if (isEmpty()) {
        return;
    }

    int data = dequeue();
    reverseQueue();
    enqueue(data);
}

// Function to display the queue
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    initQueue();

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Queue\n");
        printf("4. Reverse Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                displayQueue();
                break;

            case 4:
                reverseQueue();
                printf("Queue reversed.\n");
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
