#include<stdio.h>
#include <stdlib.h>
#include<math.h>

#define MAX 20
#define E 0.0001
#define g(x) (exp(x)-2) //exp(x)-x-2=0, x=exp(x)-2

int main(){   
    system("clear");
    int count=1; float x0,x1,error;
    printf("Enter the initial guess valueP: ");
    scanf("%f",&x0);
    while (count<MAX) {
        x1=g(x0); error=x1-x0;
        if(fabs(error)<E) {
            printf("The root is %f",x1);
            printf("\nNo. of iterations is %d",count);
            break;
        } else {
            x0=x1;
            count++;
            if(count>=MAX) {
                printf("The process didn\'t converge.");
                break;
            }
        }
    }
    return 0;
}