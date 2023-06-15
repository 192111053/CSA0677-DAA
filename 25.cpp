#include <stdio.h>

// Function to perform Strassen's matrix multiplication
void strassenMatrixMultiply(int n, int A[][n], int B[][n], int C[][n]) {
    // Base case: If the matrix size is 1x1
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Splitting the matrices into smaller submatrices
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize];
    int M5[newSize][newSize], M6[newSize][newSize], M7[newSize][newSize];

    int i, j;

    // Splitting the input matrices into submatrices
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculating the products of submatrices recursively
    strassenMatrixMultiply(newSize, A11, B11, M1);
    strassenMatrixMultiply(newSize, A12, B21, M2);
    strassenMatrixMultiply(newSize, A11, B12, M3);
    strassenMatrixMultiply(newSize, A12, B22, M4);
    strassenMatrixMultiply(newSize, A21, B11, M5);
    strassenMatrixMultiply(newSize, A22, B21, M6);
    strassenMatrixMultiply(newSize, A21, B12, M7);

    // Calculating the result submatrices
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C11[i][j] = M1[i][j] + M2[i][j];
            C12[i][j] = M3[i][j] + M4[i][j];
            C21[i][j] = M5[i][j] + M6[i][j];
            C22[i][j] = M7[i][j] - M2[i][j] + M4[i][j] + M6[i][j];
        }
    }

    // Combining the result submatrices into the final matrix C
    for (i = 0; i < newSize; i++) {
        for (j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

// Function to print a matrix
void printMatrix(int n, int mat[][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Example usage
int main() {
    int n = 4; // Size of the matrices (Assuming it is a power of 2)
    int A[][4] = {{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}};
    int B[][4] = {{1, 2, 3, 4},
                  {5, 6, 7, 8},
                  {9, 10, 11, 12},
                  {13, 14, 15, 16}};
    int C[n][n];

    strassenMatrixMultiply(n, A, B, C);

    printf("Matrix A:\n");
    printMatrix(n, A);

    printf("\nMatrix B:\n");
    printMatrix(n, B);

    printf("\nMatrix C (Result of multiplication):\n");
    printMatrix(n, C);

    return 0;
}
