#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int queue[MAX];
int front = -1, rear = -1;


int isEmpty() {
    return front == -1;
}

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = vertex;
}


int dequeue() {
    if (isEmpty()) {
        printf("Queue underflow\n");
        return -1;
    }
    int vertex = queue[front];
    if (front == rear) {
        front = rear = -1;  
    } else {
        front++;
    }
    return vertex;
}


void BFS(int graph[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX];
    

    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    

    enqueue(startVertex);
    visited[startVertex] = 1;
    printf("BFS Traversal: ");
    
    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
 
        for (int i = 0; i < vertices; i++) {
            if (graph[currentVertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() 
{
    int vertices, startVertex;
    int graph[MAX][MAX];
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);
    
    
    if (startVertex < 0 || startVertex >= vertices) {
        printf("Invalid starting vertex!\n");
        return 1;
    }
    
    
    BFS(graph, vertices, startVertex);
    
    return 0;
}
