#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (pow(x,3) - 10*x - 10)
#define tolerance 0.0001
#define maxIterations 200

void falsePosition(double a, double b) {
    double c;

    if (f(a) * f(b) >= 0) {
        printf("Invalid guesses. The function values at the boundariy must have opposite signs.\n");
        return;
    }

    for (int i = 0; i < maxIterations; i++) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        if (fabs(b - a) < tolerance || fabs(f(c)) < tolerance) {
            printf("The root is %.6lf after %d iterations\n", c, i + 1);
            return;
        } else if (f(c) * f(a) < 0) {
            b = c; // Root is between a and 
        } else {
            a = c; // Root is between c and b
        }
    }
    printf("The method did not converge. The best estimate is %.6lf\n", maxIterations, c);
}

int main() {
    system("clear");
    double a = -10, b = 10;
    falsePosition(a, b);
    return 0;
}
