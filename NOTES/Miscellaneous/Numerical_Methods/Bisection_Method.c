#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 50
#define Error 0.00001
#define f(x) (x*x-4*x-10)

float bisection(float x1,float x2) {
    float x0;
    static int count=0;
    if((f(x1)*f(x2))>0) {
        printf("\n The guess Values do not enclose a root\n");
        exit(EXIT_FAILURE);
    } else {
        x0=(x1+x2)/2;
        if (fabs(f(x0))<Error) {
            return x0;
        } else {
            x0=(x1+x2)/2;
            if (f(x0)>0) {
                count++;
                return bisection(x1,x0);
            } else if (f(x0)<0) {
                count++;
                return bisection(x0,x2);
            }
            if (count>MAX) {
                printf("\n The process didn't converge\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

int main() {
    system("clear");
    float InitialGuessValue1, InitialGuessValue2;
    printf("Enter two initial guess values x1 and x2: ");
    scanf("%f %f", &InitialGuessValue1,&InitialGuessValue2);
    printf("\n The Root was found to be: %f\n",bisection(InitialGuessValue1,InitialGuessValue2));
}