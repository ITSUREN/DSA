#include <stdio.h>
#include <math.h>

#define MAX 10
#define E 0.0001
#define N 100

int main() {
    int k,n; float a[MAX][MAX+1], x[MAX], x0[MAX], sum;

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

    // Jacobi Iteration
    for (k = 1; k <= N; k++) {
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * x0[j];
                }
            }
            x[i] = (-sum + a[i][n]) / a[i][i];
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
