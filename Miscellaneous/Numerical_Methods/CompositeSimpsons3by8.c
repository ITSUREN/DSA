#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (pow(x, 2) + 1) // Example function: f(x) = x^3 + 1

int main() {
    system("clear");
    int n; float a, b, h, sum = 0.0, integral;

    // Input the initial and final values of x and the number of segments
    printf("Enter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);
    printf("Enter the number of segments (multiple of 3): ");
    scanf("%d", &n);

    if (n % 3 != 0) {
        printf("Number of segments must be a multiple of 3.\n");
        return 1;
    }

    // Calculate the width of each subinterval
    h = (b - a) / n;

    // Apply Composite Simpson's 3/8 Rule
    for (int i = 1; i < n; i++) {
        if (i % 3 == 0) {
            sum += 2 * f(a + i * h);
        } else {
            sum += 3 * f(a + i * h);
        }
    }

    integral = (3 * h / 8) * (f(a) + sum + f(b));

    // Output the result
    printf("\nThe integration   is: %f\n", integral);

    return 0;
}
