#include <stdio.h>

#define MAX_NODES 100

int adjMatrix[MAX_NODES][MAX_NODES];
int numNodes = 0;

void addNode() {
    numNodes++;
    printf("Node %d added.\n", numNodes);
}

void addEdge(int node1, int node2) {
    adjMatrix[node1][node2] = 1;
    adjMatrix[node2][node1] = 1;
    printf("Edge added between Node %d and Node %d.\n", node1, node2);
}

void deleteNode(int node) {
    for (int i = node; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            adjMatrix[i][j] = adjMatrix[i + 1][j]; // Shift rows up
            adjMatrix[j][i] = adjMatrix[j][i + 1]; // Shift columns left
        }
    }
    numNodes--;
    printf("Node %d deleted.\n", node);
}

void displayGraph() {
    printf("Adjacency Matrix:\n");
    for (int i = 1; i <= numNodes; i++) {
        for (int j = 1; j <= numNodes; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    addNode(); // Node 1
    addNode(); // Node 2
    addNode(); // Node 3

    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(1, 3);

    printf("\nGraph before deleting a node:\n");
    displayGraph();

    deleteNode(2);

    printf("\nGraph after deleting node 2:\n");
    displayGraph();

    return 0;
}
