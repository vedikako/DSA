#include <stdio.h>
#define MAX 6  // Maximum number of nodes in the graph

// DFS function
void DFS(int A[MAX][MAX], int visited[MAX], int i, int n) {
    printf("%d ", i);    // Print the current node
    visited[i] = 1;      // Mark the current node as visited

    for (int v = 0; v < n; v++) {
        if (A[i][v] == 1 && visited[v] == 0) {  // Check for an edge and if v is unvisited
            DFS(A, visited, v, n);  // Recursive call for the next node
        }
    }
}

int main() {
    // Adjacency matrix representation of the graph
    int A[MAX][MAX] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 0}
    };

    int visited[MAX] = {0};  // Array to keep track of visited vertices
    int startNode = 0;       // Starting node for DFS
    printf("DFS traversal starting from node %d:\n", startNode);
    DFS(A, visited, startNode, MAX);

    return 0;
}
