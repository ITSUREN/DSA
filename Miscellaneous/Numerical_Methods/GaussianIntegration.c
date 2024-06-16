#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (pow(x,2)+1)

int main() {
    system("clear");
    int n=2; float a,b,c,k[5],x[5],z[5],w[5],Ig=0;
    printf("Enter the initial value of x: ");
    scanf("%f",&a);
    printf("Enter the final value of x: ");
    scanf("%f",&b);

    z[0]=-1/sqrt(3);
    z[1]=-z[0];
    w[0]=w[1]=1;

    c=(b-a)/2;
    for(int i=0;i<n;i++)
        x[i]=c*z[i]+(b+a)/2;
    for(int i=0;i<n;i++){
        k[i]=f(x[i]);
        Ig+=w[i]*k[i];
    }
    Ig=c*Ig;

    printf("\nThe integration is %f",Ig);
    return 0;
}