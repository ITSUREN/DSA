#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// A utility function to find the subset of an element 'i'
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A utility function to perform union of two subsets
void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare function used by qsort to sort edges based on their weights
int compare(const void* a, const void* b) {
    struct Edge* aEdge = (struct Edge*)a;
    struct Edge* bEdge = (struct Edge*)b;
    return aEdge->weight - bEdge->weight;
}

// Function to construct MST using Kruskal's algorithm
void KruskalMST(struct Edge* edges, int numEdges, int numVertices) {
    struct Edge result[numVertices]; // Stores the constructed MST
    int e = 0; // An index variable used for result[]
    int i = 0; // An index variable used for sorted edges

    // Sort all edges in increasing order of their weights
    qsort(edges, numEdges, sizeof(edges[0]), compare);

    // Allocate memory for creating subsets
    struct Subset* subsets = (struct Subset*)malloc(numVertices * sizeof(struct Subset));

    // Initialize subsets for each vertex
    for (int v = 0; v < numVertices; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to (numVertices - 1)
    while (e < numVertices - 1 && i < numEdges) {
        // Pick the smallest edge
        struct Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        // If including this edge does not cause cycle, include it in the result and increment the index of result for next edge
        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    // Print the edges of MST
    printf("Edges of MST:\n");
    int minCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d - %d  Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Minimum Cost of MST: %d\n", minCost);

    free(subsets);
}

// Driver program to test above functions
int main() {
    int numVertices = 4;
    int numEdges = 5;
    struct Edge edges[] = {
        // src, dest, weight
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    KruskalMST(edges, numEdges, numVertices);

    return 0;
}
