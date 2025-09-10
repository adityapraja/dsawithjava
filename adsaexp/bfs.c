#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX]; 
int front = -1, rear = -1;

int main() 
{
    int vertices, startVertex;
    int graph[MAX][MAX];    //initiates a graph
    
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);     //inputs the number of vertices

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++)      //inputs the adjacency matrix
    {
        for (int j = 0; j < vertices; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    printf("Enter the starting vertex (0 to %d): ", vertices - 1);
    scanf("%d", &startVertex);      //inputs the starting point of traversal
    
    
    if (startVertex < 0 || startVertex >= vertices) 
    {
        printf("Invalid starting vertex!\n");
        return 1;               //to check if the starting point is valid or not
    }
    
    
    BFS(graph, vertices, startVertex);  //calls the function
    
    return 0;
}

int isEmpty() 
{
    return front == -1;
}

void enqueue(int vertex)        //inserts the elements in queue from rear side
{
    if (rear == MAX - 1) 
    {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) 
    {
        front = 0;
    }
    queue[++rear] = vertex;
}


int dequeue()   //deletes the elements from front side
{
    if (isEmpty()) 
    {
        printf("Queue underflow\n");
        return -1;
    }
    int vertex = queue[front];
    if (front == rear) 
    {
        front = rear = -1;  
    } else 
    {
        front++;
    }
    return vertex;
}


void BFS(int graph[MAX][MAX], int vertices, int startVertex) 
{
    int visited[MAX];   //initiates an array for visited nodes
    for (int i = 0; i < vertices; i++) 
    {
        visited[i] = 0;     //assigns all nodes as unvisited
    }   
    enqueue(startVertex);   //initiates the traversal 
    visited[startVertex] = 1;
    printf("BFS Traversal: ");
    
    while (!isEmpty())  //loop for traversing the adjacent nodes
    {                           
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
 
        for (int i = 0; i < vertices; i++) 
        {
            if (graph[currentVertex][i] == 1 && visited[i] == 0)    
            {
                enqueue(i);     //if the condition is fulfilled it is enqueued
                visited[i] = 1; //queue front element is visited
            }
        }
    }
    printf("\n");
}
