#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

// Function to find the vertex with minimum key value not yet included in MST
int FindMinKey(int key[], bool mstSet[], int V) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print MST and its total cost
void PrintMST(int parent[], int graph[][100], int V) {
    int totalCost = 0;
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}

// Function implementing Prim's algorithm
void PrimMST(int graph[][100], int V) {
    int parent[V];   // Array to store MST
    int key[V];      // Key values to pick minimum weight edge
    bool mstSet[V];  // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    // Start from first vertex
    key[0] = 0;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        int u = FindMinKey(key, mstSet, V);
        mstSet[u] = true;

        // Update key and parent for adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    PrintMST(parent, graph, V);
}

// Main function
int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int graph[100][100];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (i == j) {
                graph[i][j] = 0; // No self-loop
            }
        }
    }

    PrimMST(graph, V);

    return 0;
}
