//Program to represent a relation using a boolean matrix
#include <stdio.h>

#define N 3  // Size of the set

void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int set[N] = {1, 2, 3};  // Example set
    int relation[N][N] = {0};  // Initialize the matrix to 0

    // Example relation: (1,1), (2,2), (3,3), (1,2)
    relation[0][0] = 1;
    relation[1][1] = 1;
    relation[2][2] = 1;
    relation[0][1] = 1;

    printf("Boolean matrix representation of the relation:\n");
    printMatrix(relation);

    return 0;
}
