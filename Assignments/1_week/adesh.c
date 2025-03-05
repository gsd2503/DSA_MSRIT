#include <stdio.h>
#include <stdlib.h>

// Structure for a task
typedef struct Task {
    int id, priority;
    struct Task *next;
} Task;

// Structure for a priority queue
typedef struct {
    Task *front;
} PriorityQueue;

// Create a new task
Task* createTask(int id, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->id = id;
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

// Insert task into the queue maintaining priority order
void enqueue(PriorityQueue *pq, int id, int priority) {
    Task* newTask = createTask(id, priority);
    if (!pq->front || pq->front->priority < priority) {
        newTask->next = pq->front;
        pq->front = newTask;
    } else {
        Task* temp = pq->front;
        while (temp->next && temp->next->priority >= priority)
            temp = temp->next;
        newTask->next = temp->next;
        temp->next = newTask;
    }
}

// Remove and execute the highest priority task
void dequeue(PriorityQueue *pq) {
    if (!pq->front) {
        printf("No tasks to execute.\n");
        return;
    }
    Task* temp = pq->front;
    printf("Executing Task ID: %d with Priority: %d\n", temp->id, temp->priority);
    pq->front = pq->front->next;
    free(temp);
}

// Display the queue
void displayQueue(PriorityQueue *pq) {
    for (Task* temp = pq->front; temp; temp = temp->next)
        printf("[Task ID: %d, Priority: %d] -> ", temp->id, temp->priority);
    printf("NULL\n");
}

int main() {
    PriorityQueue pq = {NULL};
    int n, id, priority;
    
    printf("Enter the number of tasks: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter Task ID and Priority: ");
        scanf("%d %d", &id, &priority);
        enqueue(&pq, id, priority);
    }
    
    printf("\nTask Queue:\n");
    displayQueue(&pq);
    
    printf("\nExecuting tasks:\n");
    while (pq.front)
        dequeue(&pq);
    
    return 0;
}