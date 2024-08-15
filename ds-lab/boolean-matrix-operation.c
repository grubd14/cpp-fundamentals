
#include <stdio.h>

#define N 3  // Size of the matrix (N x N)

// Function to perform Join (OR) operation on two Boolean matrices
void join(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat1[i][j] || mat2[i][j];
        }
    }
}

// Function to perform Product (AND) operation on two Boolean matrices
void product(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = mat1[i][j] && mat2[i][j];
        }
    }
}

// Function to perform Boolean Product of two matrices
void booleanProduct(int mat1[N][N], int mat2[N][N], int result[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] = result[i][j] || (mat1[i][k] && mat2[k][j]);
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[N][N] = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int mat2[N][N] = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };

    int result[N][N];

    // Perform and print Join (OR) operation
    printf("Join (OR) operation:\n");
    join(mat1, mat2, result);
    printMatrix(result);

    // Perform and print Product (AND) operation
    printf("\nProduct (AND) operation:\n");
    product(mat1, mat2, result);
    printMatrix(result);

    // Perform and print Boolean Product operation
    printf("\nBoolean Product operation:\n");
    booleanProduct(mat1, mat2, result);
    printMatrix(result);

    return 0;
}
