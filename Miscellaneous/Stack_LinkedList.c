#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

struct Node_SL{
    int Item;
    struct Node_SL *Next;
};

typedef struct Node_SL Node;

Node *Top=NULL; //Is actually at the bottom depending on how you look 

int isEmpty() {
    return (Top==NULL);
}

// GETS
int getItem() {
    int Item;
    printf("\nEnter the Element: ");
    scanf("%d", &Item);
    return Item;
}

int NodeCount() {
    Node *temp = Top;
    int NodeCount=0;
    while (temp!=NULL) {
        NodeCount++;
        temp = temp->Next;
    }
    return NodeCount;
}

// Methods 
void push() {
    Node *NewNode = (Node *) malloc (sizeof(Node));
    int Item=getItem();
    NewNode -> Item = Item;
    NewNode -> Next = NULL;
    if(isEmpty()) {
        Top = NewNode;
    } else {
        NewNode->Next=Top;
        Top = NewNode; // Goes Down
    }
}

int pop() {
    Node *NewNode = (Node *) malloc (sizeof(Node));
    Node *Hold;
    if (isEmpty()) {
        printf("\n Stack is Empty. Cannot Pop an element.");
    } else {
        Hold = Top;
        printf("\n Popped Item: %d",Top->Item);
        Top=Top->Next;
        free(Hold);
    }
}

void traverse() {
    Node *temp = Top;
    printf("\n The Elements in the Stacks are: [ ");
    if (!isEmpty()) {
        for (int i=0;temp->Next!=NULL;i++) {
            printf("%d,",temp->Item);
            temp=temp->Next;
        }
        printf("%d,",temp->Item);
    }
    printf("\b ]\b");
}

void menu(int *choice) {
    printf("\nMENU: Number of Stack Elements: %d\n\n1. Push\n2. Pop\n3. Traverse\n\n=> ",NodeCount());
    scanf("%d",choice);
    switch (*choice)
    {
    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        traverse();
        break;
    default:
        printf("\n[ERR 03]: Enter a Valid Option");
        break;
    }
}

int main(){
    int choice=0;

    do {
        system("clear");
        menu(&choice);
    } while (choice != 0);

    printf("\nExiting Program.");
}