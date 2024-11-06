#include <stdio.h>

#define N 4  // Number of nodes

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int adjMatrix[N][N] = {0};  // Initialize a 4x4 matrix with 0s

    // Adding edges
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1;  // For undirected graph, mark both [i][j] and [j][i]
    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;
    adjMatrix[2][3] = 1;
    adjMatrix[3][2] = 1;

    printf("Adjacency Matrix:\n");
    printMatrix(adjMatrix);

    return 0;
}
