#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n = 4; 
    int capacity = 8;
    int values[] = {1, 2, 5, 6};
    int weights[] = {2, 3, 4, 5};

    int dp[n + 1][capacity + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0; // Base case
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    system("clear");
    printf("Maximum value in Knapsack of capacity %d = %d\n", capacity, dp[n][capacity]);

    printf("Items included (0-based indices): ");
    int w = capacity;
    for (int i = n; i > 0 && dp[i][w] > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("I%d ", i); 
            w -= weights[i - 1];
        }
    }
}
