#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (pow(x, 2) + 1) // Example function: f(x) = x^2 + 1

int main() {
    systemc("cls");
    float a, b, Ig;

    // Input the initial and final values of x
    printf("Enter the initial value of x: ");
    scanf("%f", &a);
    printf("Enter the final value of x: ");
    scanf("%f", &b);

    // Apply the trapezoidal rule
    Ig = (b - a) * (f(a) + f(b)) / 2.0;

    // Output the result
    printf("\nThe integration result is: %.6f\n", Ig);

    return 0;
}
