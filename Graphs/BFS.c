#include <stdio.h>
#define MAX 6

int queue[MAX];  // Queue for BFS
int front = -1, rear = -1;  // Queue pointers

void enqueue(int data) {
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = data;
    }
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int data = queue[front++];
        if (front > rear) {  // Reset the queue when empty
            front = rear = -1;
        }
        return data;
    }
}

int isEmpty() {
    return front == -1;
}

void BFS(int A[MAX][MAX], int visited[MAX], int i, int n) {
    int u, v;
    printf("%d ", i);  // Print the starting node
    visited[i] = 1;    // Mark as visited
    enqueue(i);        // Enqueue the starting node

    while (!isEmpty()) {
        u = dequeue();  // Dequeue a vertex from the queue
        for (v = 0; v < n; v++) {
            // Check for an edge and if the vertex has not been visited
            if (A[u][v] == 1 && visited[v] == 0) {
                printf("%d ", v);  // Print the vertex
                visited[v] = 1;    // Mark as visited
                enqueue(v);        // Enqueue the vertex
            }
        }
    }
}

int main() {
    int A[MAX][MAX] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    int visited[MAX] = {0};  // Array to keep track of visited vertices
    int startNode = 0;       // Starting node for BFS
    printf("BFS traversal starting from node %d:\n", startNode);
    BFS(A, visited, startNode, MAX);

    return 0;
}
