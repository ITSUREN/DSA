#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10
#define f(x) (pow(x,2)+1)

int main(){
    system("clear");
    int n;float a,b,f[MAX],h,sum=0,Ig;

    printf("Enter the initial value of x: ");
    scanf("%f",&a);
    printf("Enter the final value of x: ");
    scanf("%f",&b);
    printf("Enter the no. of segments: ");
    scanf("%d",&n);

    h=(b-a)/n;
    for(int i=0;i<=n;i++)
        f[i]=f(a+i*h);
    for(int i=1;i<=n-1;i++)
        sum+=f[i];
    Ig=h/2*(f[0]+f[n]+2*sum);

    printf("\nThe integration is %f",Ig);
    return 0;

}