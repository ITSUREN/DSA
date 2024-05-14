#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Structure to represent a node in the adjacency list
struct AdjListNode {
    int Destination;
    struct AdjListNode* next;
};

// Structure to represent the adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure to represent the graph
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int Destination) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->Destination = Destination;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int Source, int Destination) {
    struct AdjListNode* newNode = newAdjListNode(Destination);
    newNode->next = graph->array[Source].head;
    graph->array[Source].head = newNode;

    newNode = newAdjListNode(Source);
    newNode->next = graph->array[Destination].head;
    graph->array[Destination].head = newNode;
}

// BFS traversal
void BFS(struct Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    int visited[MAX_VERTICES] = {0};

    // Create a queue for BFS
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Get all adjacent vertices of the dequeued vertex currentVertex
        // If an adjacent vertex has not been visited, then mark it visited and enqueue it
        struct AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->Destination;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[rear++] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

// Utility function for DFS
void DFSUtil(struct Graph* graph, int v, int visited[]) {
    // Mark the current node as visited and print it
    visited[v] = 1;
    printf("%d ", v);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* temp = graph->array[v].head;
    while (temp) {
        int adjVertex = temp->Destination;
        if (!visited[adjVertex])
            DFSUtil(graph, adjVertex, visited);
        temp = temp->next;
    }
}

// DFS traversal
void DFS(struct Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    int visited[MAX_VERTICES] = {0};

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, startVertex, visited);
}

// Driver program to test above functions
int main() {
    // Create a graph given in the above diagram
    int numVertices = 4;
    struct Graph* graph = createGraph(numVertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printf("BFS traversal starting from vertex 0: ");
    BFS(graph, 0);
    printf("\n");

    printf("DFS traversal starting from vertex 0: ");
    DFS(graph, 0);
    printf("\n");

    return 0;
}
