#include <stdio.h>
#include <limits.h>

#define V 9 // Number of vertices in the graph

// Function to find the vertex with the minimum distance value, from the set of vertices not yet included in the shortest path tree
int minDistance(int Distance[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && Distance[v] <= min) {
            min = Distance[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm for a given graph
void dijkstra(int graph[V][V], int Source) {
    int Distance[V]; // The output array. dist[i] will hold the shortest distance from Source to i

    int sptSet[V]; // (Shortest Path Tree)Set[i] will be true if vertex i is included in the shortest path tree or shortest distance from Source to i is finalized

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        Distance[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    Distance[Source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(Distance, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it's not in sptSet, there's an edge from u to v, and total weight of path from Source to v through u is smaller than current value of dist[v]
            if ((!sptSet[v]) && (graph[u][v]) && (Distance[u] != INT_MAX) && ((Distance[u] + graph[u][v]) < Distance[v]))
                Distance[v] = Distance[u] + graph[u][v];
        }
    }

    // Print the constructed distance array
    printSolution(Distance);
}

// Driver program to test above function
int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
