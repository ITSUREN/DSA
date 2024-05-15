#include <stdio.h>
#include <stdlib.h>

int Factorial(int value) {
    if (value<=1) {
        return value;
    } else {
        return value*Factorial(value-1);
    }
}

int main() {
    int Number;
    system("cls");
    printf("\nEnter the number: ");
    scanf("%d",&Number);
    printf("\n The Factorial is: %d", Factorial(Number));
}