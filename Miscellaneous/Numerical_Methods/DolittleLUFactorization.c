#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void printMatrix(float A[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.3f\t", A[i][j]);
        }
        printf("\n");
    }
}

void doolittleLU(float A[MAX][MAX], float L[MAX][MAX], float U[MAX][MAX], int n) {
    // Initialize L as identity matrix and U as zero matrix
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;  // Diagonal of L is 1
        for (int j = 0; j < n; j++) {
            U[i][j] = 0.0;
        }
    }

    // Perform LU decomposition
    for (int k = 0; k < n; k++) {
        // Calculate U matrix
        for (int j = k; j < n; j++) {
            float sum = 0.0;
            for (int p = 0; p < k; p++) {
                sum += L[k][p] * U[p][j];
            }
            U[k][j] = A[k][j] - sum;
        }

        // Calculate L matrix
        for (int i = k + 1; i < n; i++) {
            float sum = 0.0;
            for (int p = 0; p < k; p++) {
                sum += L[i][p] * U[p][k];
            }
            L[i][k] = (A[i][k] - sum) / U[k][k];
        }
    }
}

int main() {
    system("clear");
    int n;float A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];

    // Input size of matrix
    printf("Enter the size of the square matrix (max %d): ", MAX);
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter %dx%d elements of the matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Perform Doolittle LU decomposition
    doolittleLU(A, L, U, n);

    // Output results
    printf("\nMatrix A:\n");
    printMatrix(A, n);

    printf("\nLower triangular matrix L:\n");
    printMatrix(L, n);

    printf("\nUpper triangular matrix U:\n");
    printMatrix(U, n);

    return 0;
}
