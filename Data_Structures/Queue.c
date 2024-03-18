#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
    int Item[MAX_SIZE];
    int Front;
    int Rear;
} LinearQueue;

void InitializeQueue_Linear(LinearQueue *LQueue) {
    LQueue->Rear = -1;
    LQueue->Front = 0;
}

int isFull_Linear(LinearQueue *LQueue) {
    return (LQueue->Rear == MAX_SIZE - 1);
}

int isEmpty_Linear(LinearQueue *LQueue) {
    return (LQueue->Rear < LQueue->Front);
}

void Enqueue_Linear(LinearQueue *LQueue) {
    int Item;
    printf("\nEnter the Value to be Pushed: ");
    scanf("%d", &Item);
    if (isFull_Linear(LQueue)) {
        printf("\n[ERR 01] Queue is in Overflow Condition.");
        exit(EXIT_FAILURE);
    } else {
        LQueue->Item[++(LQueue->Rear)] = Item;
    }
}

int Dequeue_Linear(LinearQueue *LQueue) {
    if (isEmpty_Linear(LQueue)) {
        printf("\n[ERR 02] Queue is in Underflow Condition");
        exit(EXIT_FAILURE);
    } else {
        return LQueue->Item[(LQueue->Front)++];
    }
}

int Peek_Linear(LinearQueue *LQueue, int index) {
    return LQueue->Item[index];
}

void Display_Linear(LinearQueue *LQueue) {
    printf("\nThe Content of the Queue are: [ ");
    for (int i = LQueue->Front; i <= LQueue->Rear; i++) {
        printf("%d,", Peek_Linear(LQueue, i)); // Using Peek_Linear function
    }
    printf("\b ]");
}

void menu(LinearQueue *LQueue, int *choice) {
    printf("\nMENU:\n\n1. Enqueue\n2. Dequeue\n3. Display\n\n=> ");
    scanf("%d", choice);
    switch (*choice) {
        case 1:
            Enqueue_Linear(LQueue);
            break;
        case 2:
            Dequeue_Linear(LQueue);
            break;
        case 3:
            Display_Linear(LQueue);
            break;
        default:
            printf("\n[ERR 03]: Enter a Valid Option");
            break;
    }
}

int main() {
    LinearQueue LQueue;
    int choice = 0;

    InitializeQueue_Linear(&LQueue);

    do {
        system("clear");
        menu(&LQueue, &choice);
    } while (choice != 0);

    printf("\nExiting Program.");
}
