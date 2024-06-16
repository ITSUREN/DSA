#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10

int main() {
    system("clear");
    int n; float a[MAX][MAX+1], x[MAX], c, sumx;

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (%dx%d elements):\n", n, n + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Elimination process
    for(int k = 0; k < n - 1; k++) {
        for(int i = k + 1; i < n; i++) {
            c = a[i][k] / a[k][k];
            for(int j = k; j < n + 1; j++) {
                a[i][j] = a[i][j] - c * a[k][j];
            }
        }
    }

    // Printing the upper triangular matrix
    printf("The upper triangular matrix is:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n + 1; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    // Backward substitution
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for(int i = n - 2; i >= 0; i--) {
        sumx = 0;
        for(int j = i + 1; j < n; j++) {
            sumx += x[j] * a[i][j];
        }
        x[i] = (a[i][n] - sumx) / a[i][i];
    }

    // Printing the solution
    printf("The solution is:\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, x[i]);
    }
    return 0;
}
