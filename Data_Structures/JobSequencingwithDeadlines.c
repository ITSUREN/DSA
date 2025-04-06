#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

// Job structure
typedef struct {
    char id[3];
    int profit;
    int deadline;
} Job;

// Comparator for sorting by profit (descending)
int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;
}

int main() {
    int n = 4;
    Job jobs[] = {
        {"J1", 100, 2},
        {"J2", 10, 1},
        {"J3", 15, 2},
        {"J4", 27, 1}
    };

    // Step 1: Sort jobs by profit descending
    qsort(jobs, n, sizeof(Job), compare);

    // Step 2: Find max deadline
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline) {
            maxDeadline = jobs[i].deadline;
        }
    }

    // Step 3: Schedule jobs
    char schedule[MAX][3]; // To store job IDs
    int slotFilled[MAX] = {0}; // 0 = free, 1 = taken
    int totalProfit = 0;

    for (int i = 0; i < maxDeadline; i++) {
        strcpy(schedule[i], "-");
    }

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (!slotFilled[j]) {
                strcpy(schedule[j], jobs[i].id);
                slotFilled[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    system("clear");
    printf("Job Schedule: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (strcmp(schedule[i], "-") != 0)
            printf("%s ", schedule[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}
