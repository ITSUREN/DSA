#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
#define E 0.0001
#define N 100

int main() {
    system("clear");
    int k,n;float a[MAX][MAX+1], x[MAX], x0[MAX], sum1, sum2;

    // Input the number of unknowns and the augmented matrix
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter %dx%d elements for the augmented matrix:\n", n, n+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    // Initialize x0 (initial guess for solutions)
    for (int i = 0; i < n; i++) {
        x0[i] = 0;
    }

    // Gauss-Seidel Iteration
    for (k = 1; k <= N; k++) {
        for (int i = 0; i < n; i++) {
            sum1 = sum2 = 0;
            for (int j = 0; j < i; j++) {
                sum1 += a[i][j] * x[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum2 += a[i][j] * x0[j];
            }
            x[i] = (-sum1 - sum2 + a[i][n]) / a[i][i];
            printf("%.3f\t", x[i]);
        }
        printf("\n");

        // Check for convergence
        int converged = 1;
        for (int i = 0; i < n; i++) {
            if (fabs(x[i] - x0[i]) / x[i] > E) {
                converged = 0;
                break;
            }
        }
        if (converged) {
            break;
        }

        // Update x0 for the next iteration
        for (int i = 0; i < n; i++) {
            x0[i] = x[i];
        }
    }

    // Output the results
    if (k > N) {
        printf("Maximum number of iterations exceeded.\n");
    } else {
        printf("The solution set is:\n");
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %.3f\n", i + 1, x[i]);
        }
    }
    printf("Number of iterations: %d\n", k);

    return 0;
}
