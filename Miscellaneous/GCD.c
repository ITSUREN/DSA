#include <stdio.h>
#include <stdlib.h>

int GCD(int x, int y) {
    if (y==0) {
        return x;
    } else {
        return GCD(y,x%y);
    }
}

int main() {
    int firstNumber,secondNumber;
    system("clear");
    printf("\nEnter any two numbers: ");
    scanf("%d %d",&firstNumber,&secondNumber);
    printf("\n The GCD of %d and %d is: %d\n", firstNumber, secondNumber,GCD(firstNumber,secondNumber));
    
}