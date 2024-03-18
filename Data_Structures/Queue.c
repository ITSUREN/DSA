#include <stdio.h>
#include <stdlib.h>
#include "./modules/Linear_Queue.c"
#include "./modules/Circular_Queue.c"
#include "./modules/Priority_Queue.c"

#define MAX_SIZE 50

void menu() {
    int choice;
    system("clear");
    printf("\nMENU:\n\n1. Linear Queue\n2. Circular Queue [Maybe Buggy]\n3. Priority Queue\n\n=>");
    scanf("%d",&choice);
    switch (choice) {
        case 1:
            LinearQueue_Interface();
            break;
        case 2:
            CircularQueue_Interface();
            break;
        case 3:
            PriorityQueue_Interface();
            break;
        default:
            printf("\n[ERR 01] Invalid Input\n");
            break;
    }
}

int main() {
    menu();
    printf("\nExiting Program.\n");
}
