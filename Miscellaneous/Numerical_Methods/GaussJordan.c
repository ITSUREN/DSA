#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10

int main() {
    system("clear");
    int n; float a[MAX][MAX+1], c;

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter %dx%d elements for the augmented matrix:\n", n, n + 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Forward elimination to convert the matrix to row echelon form
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(i != k) {
                c = a[i][k] / a[k][k];
                for(int j = k; j <= n; j++) {
                    a[i][j] = a[i][j] - c * a[k][j];
                }
            }
        }
    }

    // Normalizing the diagonal elements to 1 and printing the reduced echelon form
    printf("\nThe reduced echelon form matrix is:\n");
    for(int i = 0; i < n; i++) {
        a[i][n] /= a[i][i];
        a[i][i] = 1.0; // Making diagonal element identity
        for(int j = 0; j <= n; j++) {
            printf("%.2f\t", a[i][j]);
        }
        printf("\n");
    }

    // Printing the solution set
    printf("\nThe solution set is:\n");
    for(int i = 0; i < n; i++) {
        printf("x[%d] = %.4f\n", i + 1, a[i][n]);
    }

    return 0;
}
