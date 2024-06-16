#include <stdio.h>
#include <stdlib.h>

// Define the function for which we want to calculate the derivative
#define f(x) ((x) * (x))

// Function to calculate the derivative using forward difference formula
double forwardDifference(double x, double h) {
    return (f(x + h) - f(x)) / h;
}

int main() {
    system("clear");
    double x, h;
    
    // Input the point at which the derivative is to be calculated
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    
    // Input the step size
    printf("Enter the step size h: ");
    scanf("%lf", &h);
    
    // Calculate the derivative
    double derivative = forwardDifference(x, h);
    
    // Output the result
    printf("The derivative at x = %.6lf is %.6lf\n", x, derivative);
    
    return 0;
}
