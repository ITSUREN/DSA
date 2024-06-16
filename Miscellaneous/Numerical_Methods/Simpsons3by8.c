#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define f(x) (pow(x,2)+1)

int main(){
    system("clear");
    int n=3; float a,b,f[3],h,Ig;
    printf("Enter the initial value of x: ");
    scanf("%f",&a);
    printf("Enter the final value of x: ");
    scanf("%f",&b);
    h=(b-a)/n;
    for(int i=0;i<=n;i++)
        f[i]=f(a+i*h);
    Ig=3*h/8*(f[0]+f[n]+3*(f[1]+f[2]));
    printf("\nThe integration is %f",Ig);
    return 0;
}