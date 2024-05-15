#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int value) {
    if (value<=1) {
        return value;
    } else {
        return Fibonacci(value-1)+Fibonacci(value-2);
    }
}

int main() {
    int numberofTerms;
    system("cls");
    printf("\nEnter the number of Terms: ");
    scanf("%d",&numberofTerms);
    printf("\n The Fibonacci Terms are: ");
    for (int i=1;i<=numberofTerms;i++) {
        printf("%d, ",Fibonacci(i));
    }
    printf("\b\b ");
}