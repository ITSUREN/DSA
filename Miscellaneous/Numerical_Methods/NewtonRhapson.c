#include<stdio.h>
#include<math.h>

#define MAX 20
#define E 0.0001
#define f(x) (exp(x)-x-2)
#define f1(x) (exp(x)-1)

int main()
{   int count=1;
    float x0,x1;
    printf("Enter the initial guess value: ");
    scanf("%f",&x0);
    if(f1(x0)==0)
        printf("Derivative is zero at guess value.");
    else{   
        while(count<=MAX) {
            x1=x0-(f(x0)/f1(x0));
            if(fabs((x1-x0)/x1)<E) {
                printf("The root is %f",x1);
                printf("\nNo. of iterations is %d",count);
                break;
            } else {
                x0=x1;
                count++;
                if(count=MAX) {
                    printf("The process doesn\'t converge.");
                    break;
                }
            }
        }
    }
    return 0;
}