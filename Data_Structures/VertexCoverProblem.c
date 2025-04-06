#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 7
#define MAX_EDGES 8

// Edge structure
typedef struct {
    int u, v;
} Edge;

// Graph structure
typedef struct {
    int V, E;
    Edge edges[MAX_EDGES];
} Graph;

// Function to initialize the graph
void initGraph(Graph* g, int V, int E) {
    g->V = V;
    g->E = E;
}

// Function to add an edge to the graph
void addEdge(Graph* g, int u, int v, int idx) {
    g->edges[idx].u = u;
    g->edges[idx].v = v;
}

// Function to print the vertex cover
void printVertexCover(bool vertexCover[], int V) {
    printf("Vertex Cover: { ");
    for (int i = 0; i < V; i++) {
        if (vertexCover[i])
            printf("%c, ", 'a' + i);  // Print vertices as 'a', 'b', 'c', etc.
    }
    printf("\b\b}\n");
}

// Approximation Algorithm for Vertex Cover (Greedy)
void vertexCover(Graph* g) {
    bool vertexCover[g->V];
    for (int i = 0; i < g->V; i++) {
        vertexCover[i] = false;
    }

    // Iterate through the edges and greedily select vertices
    for (int i = 0; i < g->E; i++) {
        int u = g->edges[i].u;
        int v = g->edges[i].v;

        // If neither u nor v is included in the vertex cover, add both
        if (!vertexCover[u] && !vertexCover[v]) {
            vertexCover[u] = true;
            vertexCover[v] = true;
        }
    }

    // Print the vertex cover
    printVertexCover(vertexCover, g->V);
}

int main() {
    Graph g;
    int V = MAX_VERTICES;  // Number of vertices (7 vertices, a to g)
    int E = MAX_EDGES;     // Number of edges (8 edges)

    initGraph(&g, V, E);

    // Add edges to the graph (using 0-based indexing)
    addEdge(&g, 0, 1, 0);  // ab
    addEdge(&g, 1, 2, 1);  // bc
    addEdge(&g, 2, 3, 2);  // cd
    addEdge(&g, 2, 4, 3);  // ce
    addEdge(&g, 3, 4, 4);  // de
    addEdge(&g, 3, 5, 5);  // df
    addEdge(&g, 3, 6, 6);  // dg
    addEdge(&g, 4, 5, 7);  // ef

    // Find the vertex cover using the approximation algorithm
    system("clear");
    vertexCover(&g);
}
