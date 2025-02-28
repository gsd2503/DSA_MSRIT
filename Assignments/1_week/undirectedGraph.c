// Write a C Program to detect cycle in a Undirected Graph
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_NODES];
    bool visited[MAX_NODES];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph createGraph(int vertices) {
    struct Graph graph;
    graph.numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph.adjLists[i] = NULL;
        graph.visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

bool detectCycleDFS(struct Graph* graph, int v, int parent) {
    graph->visited[v] = true;
    struct Node* temp = graph->adjLists[v];
    
    while (temp) {
        if (!graph->visited[temp->vertex]) {
            if (detectCycleDFS(graph, temp->vertex, v)) {
                return true;
            }
        } else if (temp->vertex != parent) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool hasCycle(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            if (detectCycleDFS(graph, i, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int vertices = 5;
    struct Graph graph = createGraph(vertices);
    
    addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 1); // This edge creates a cycle
    
    if (hasCycle(&graph)) {
        printf("Graph contains a cycle.\n");
    } else {
        printf("Graph does not contain a cycle.\n");
    }
    
    return 0;
}
