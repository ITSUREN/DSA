#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define f(x,y) ((x)*(x)+(y)*(y)) //x^2+y^2

int main() {
    system("clear");
    int n;float x,y,h,xp,m1,m2,m3,m4;

    printf("Enter initial values of x and y: ");
    scanf("%f%f",&x,&y);
    printf("Enter x-value at which y is required: ");
    scanf("%f",&xp);
    printf("Enter step-size: ");
    scanf("%f",&h);
    
    n=((xp-x)/h);
    for(int i=1;i<=n;i++) {
        m1=f(x,y);
        m2=f(x+h/2,y+(m1*h/2));
        m3=f(x+h/2,y+(m2*h/2));
        m4=f(x+h,y+(m3*h));
        x=x+h;
        y=y+((m1+2*m2+2*m3+m4)*h)/6;
    }
    printf("\nThe value of y at x=%.2f is %.4f.",x,y);
    return 0;
}