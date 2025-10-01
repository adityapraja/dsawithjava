#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX

int FindMinKey(int key[], bool mstSet[], int V);
void PrintMST(int parent[], int graph[][100], int V);
void PrimMST(int graph[][100], int V);

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
                graph[i][j] = 0; 
            }
        }
    }

    PrimMST(graph, V);

    return 0;
}


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

void PrintMST(int parent[], int graph[][100], int V) {
    int totalCost = 0;
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}

void PrimMST(int graph[][100], int V) {
    int parent[V];  
    int key[V];      
    bool mstSet[V];  

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }


    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = FindMinKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    PrintMST(parent, graph, V);
}
