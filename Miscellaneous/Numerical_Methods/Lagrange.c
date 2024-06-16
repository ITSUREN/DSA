#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 10

int main() {
    system("clear");
    int n; float x[MAX], f[MAX], sum = 0, pro, xp, fp;
    
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    if (n > MAX || n < 1) {
        printf("Invalid number of data points [1,%d].", MAX);
        return 1;
    }
    
    for (int i = 0; i < n; i++) {  
        printf("\nInput the data points for x[%d] and f[%d]: ", i, i);
        scanf("%f %f", &x[i], &f[i]);
    }
    
    printf("\nInput the specified value of x: ");
    scanf("%f", &xp);
    
    for (int i = 0; i < n; i++) {  
        pro = 1.0;
        for (int j = 0; j < n; j++) {
            if (i != j)
                pro *= (xp - x[j]) / (x[i] - x[j]);
        }
        sum += pro * f[i];
    }
    
    fp = sum;
    printf("\nThe required functional value at %f = %f\n", xp, fp);
    
    return 0;
}
