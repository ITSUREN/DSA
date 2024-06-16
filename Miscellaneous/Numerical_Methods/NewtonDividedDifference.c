#include <stdio.h>
#include <stdlib.h>

// Function to calculate the divided difference table
void dividedDifferenceTable(double x[], double y[], int n, double **diff) {
    for (int i = 0; i < n; i++) {
        diff[i][0] = y[i];
    }
    
    // Calculating the divided differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diff[i][j] = (diff[i + 1][j - 1] - diff[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}

// Function to apply Newton's divided difference formula
double applyFormula(double x[], double **diff, double value, int n) {
    double result = diff[0][0];
    double term;

    for (int i = 1; i < n; i++) {
        term = diff[0][i];
        for (int j = 0; j < i; j++) {
            term *= (value - x[j]);
        }
        result += term;
    }

    return result;
}

int main() {
    int n; system("clear");
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    double x[n], y[n];
    double **diff = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        diff[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Creating the divided difference table
    dividedDifferenceTable(x, y, n, diff);

    // Displaying the divided difference table
    printf("\nDivided Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%lf ", diff[i][j]);
        }
        printf("\n");
    }

    double value;
    printf("Enter the value to interpolate: ");
    scanf("%lf", &value);

    // Calculating the interpolated value
    double result = applyFormula(x, diff, value, n);
    printf("The interpolated value at %.6lf is %.6lf\n", value, result);

    // Freeing allocated memory
    for (int i = 0; i < n; i++) {
        free(diff[i]);
    }
    free(diff);

    return 0;
}
