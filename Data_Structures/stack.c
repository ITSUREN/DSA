#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void InitializeStack(stack *Stacks){
    (Stacks->top)=-1;
}

// checks
int isEmpty(stack *Stacks) {
    if ((Stacks->top)==-1) {
        printf("\n[Warn 01]: Stack Empty.");
        return 1;
    } else {
        return 0;
    }
}

int isFull(stack *Stacks) {
    if ((Stacks->top) == (MAX_SIZE-1)) {
        printf("\n[Warn 02]: Stack Full.");
        return 1;
    } else {
        return 0;
    }
}

// Methods 
void push(stack *Stacks) {
    int data;
    printf("\nEnter the Data to be pushed: ");
    scanf("%d",&data);
    if (!isFull(Stacks)) {
        (Stacks->top)++;
        (Stacks->data)[Stacks->top]=data;
    } else {
        printf("\n[ERR 01]: Aborted because the stack was full");
        exit(EXIT_FAILURE);
    }
}

int pop(stack *Stacks) {
    if (!isEmpty(Stacks)) {
        int val=(Stacks->data)[Stacks->top];
        printf("\nData Popped: %d",val);
        (Stacks->top)--;
        return val;
    } else {
        printf("\n[ERR 02]: Aborted because the stack was empty");
        exit(EXIT_FAILURE);
    }
}

void traverse(stack *Stacks) {
    printf("\n The Elements in the Stacks are: [ ");
    for (int i=0;i<=Stacks->top;i++) {
        printf("%d,",(Stacks->data)[i]);
    }
    printf("\b ]\b");
}

void menu(stack *Stacks, int *choice) {
    printf("\nMENU:\n\n1. Push\n2. Pop\n3. Traverse\n\n=> ");
    scanf("%d",choice);
    switch (*choice)
    {
    case 1:
        push(Stacks);
        break;
    case 2:
        pop(Stacks);
        break;
    case 3:
        traverse(Stacks);
        break;
    default:
        printf("\n[ERR 03]: Enter a Valid Option");
        break;
    }
}

int main(){
    stack Stacks;
    int choice=0;

    InitializeStack(&Stacks);

    do {
        system("clear");
        menu(&Stacks,&choice);
    } while (choice != 0);

    printf("\nExiting Program.");
}