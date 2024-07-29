#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Queue structure for BFS
struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

// Graph structure
struct Graph {
    int vertices;
    int** adjacencyMatrix;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to enqueue an item
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->items[queue->rear] = value;
}

// Function to dequeue an item
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty!\n");
        return -1;
    }

    int item = queue->items[queue->front];
    queue->front++;

    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }

    return item;
}

// Function to create a new graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Allocate memory for the adjacency matrix
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)malloc(vertices * sizeof(int));
    }

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int start, int end) {
    graph->adjacencyMatrix[start][end] = 1;
    graph->adjacencyMatrix[end][start] = 1;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    // Mark all vertices as not visited
    bool visited[MAX_VERTICES];
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    // Create a queue for BFS
    struct Queue* queue = createQueue();

    // Mark the current node as visited and enqueue it
    visited[startVertex] = true;
    printf("BFS starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);

        // Get all adjacent vertices of the dequeued vertex
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                printf("%d ", i);
                enqueue(queue, i);
            }
        }
    }

    printf("\n");

    // Free allocated memory for the queue
    free(queue);
}

// Function to free memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->adjacencyMatrix[i]);
    }
    free(graph->adjacencyMatrix);
    free(graph);
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    BFS(graph, 0);

    // Free allocated memory for the graph
    freeGraph(graph);

    return 0;
}
