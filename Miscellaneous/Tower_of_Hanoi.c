#include <stdio.h>
#include <stdlib.h>

void TowerOfHanoi(int numberOfDisks, const char *First, const char *Second, const char *Third) {
    if (numberOfDisks) {
        TowerOfHanoi(numberOfDisks-1,First, Third, Second); 
        printf("\nMove Disk %d from %s to %s", numberOfDisks, First, Second);
        TowerOfHanoi(numberOfDisks-1,Third, Second, First);
    }
}

void main () {
    int numberOfDisks;
    system("clear");
    printf("Enter the number of Disks: ");
    scanf("%d",&numberOfDisks);
    system("clear");
    TowerOfHanoi(numberOfDisks,"Source", "Destination", "Temporary");
}