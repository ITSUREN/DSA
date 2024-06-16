#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (pow(x, 2) + 1) // Example function: f(x) = x^3 + 1

// Function to calculate the trapezoidal approximation
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < n; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

// Function to perform Romberg Integration
void rombergIntegration(double a, double b, int maxOrder) {
    double R[maxOrder][maxOrder];

    // Calculate R[0][0]
    R[0][0] = trapezoidal(a, b, 1);

    // Fill in the Romberg table
    for (int i = 1; i < maxOrder; i++) {
        // Compute the trapezoidal approximations with 2^i intervals
        R[i][0] = trapezoidal(a, b, pow(2, i));

        // Compute the Romberg extrapolations
        for (int j = 1; j <= i; j++) {
            R[i][j] = (pow(4, j) * R[i][j - 1] - R[i - 1][j - 1]) / (pow(4, j) - 1);
        }
    }

    // Print the Romberg table
    printf("\nRomberg Integration Table:\n");
    for (int i = 0; i < maxOrder; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%f ", R[i][j]);
        }
        printf("\n");
    }

    // The most accurate estimate is in R[maxOrder-1][maxOrder-1]
    printf("\nThe integral is: %f\n", R[maxOrder - 1][maxOrder - 1]);
}

int main() {
    system("clear");
    double a, b; int maxOrder;

    // Input the initial and final values of x and the maximum order of Romberg Integration
    printf("Enter the initial value of x: ");
    scanf("%lf", &a);
    printf("Enter the final value of x: ");
    scanf("%lf", &b);
    printf("Enter the maximum order: ");
    scanf("%d", &maxOrder);

    // Perform Romberg Integration
    rombergIntegration(a, b, maxOrder);

    return 0;
}
