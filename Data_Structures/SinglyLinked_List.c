#include <stdio.h>
#include <stdlib.h>
#include "./modules/c_functions_linux.c"

#define MAXSIZE 50

// Data Type Setup
typedef struct Node_SL{
    int Item;
    struct Node_SL *Next;
} Node;

// Initial Setup
Node *First=NULL;
Node *Last=NULL;

// GETS
int getItem() {
    int Item;
    printf("\nEnter the Element: ");
    scanf("%d", &Item);
    return Item;
}

int getPosix() {
    int Posix;
    printf("\nEnter the Position: ");
    scanf("%d",&Posix);
    return Posix;
}

// LOGICS
void FirstNode_logic(Node *NewNode) {
    NewNode -> Next = NULL;
    First = NewNode;
    Last = NewNode;
}

void LastNode_logic(Node *NewNode) {
    NewNode -> Next = NULL;
    Last -> Next = NewNode;
    Last = NewNode;
}

void FirstNodeSwap_logic(Node *NewNode) {
    NewNode->Next= First;
    First = NewNode;
}

void DeleteEnd_logic() {
    Node *temp = First;
    while (temp->Next->Next != NULL) { // Traverse to the second last node
        temp = temp->Next;
    }
    free(temp->Next); // Free the last node
    temp->Next = NULL; // Set the next pointer of second last node to NULL
    Last = temp; // Update the Last pointer to point to the second last node
}

// CHECKS
int isEmpty() {
    return (First==NULL);
}

// Modules
int NodeCount() {
    Node *temp = First;
    int NodeCount=0;
    while (temp!=NULL) {
        NodeCount++;
        temp = temp->Next;
    }
    return NodeCount;
}

void DEBUG_lastnode() {
    if (Last!=NULL) {
        printf("\n The last node is %d", Last->Item);
    } else {
        printf("\n The last node is NULL");
    }
    getch();
}

// Displaying
void  Display() {
    Node *temp = First;

    printf("[ ");
    while (temp!=NULL) {
        printf("%d,",temp->Item);
        temp = temp->Next;
    }
    printf("\b ]");
}

void InitialPrint() {
    static int alreadycalled=0;
    if (!alreadycalled) {
        printf("Elements Found at Nodes: ");
        alreadycalled=1;
    } 
}

// Searching
void Search() {
    Node *temp=First;
    if (isEmpty()) {
        printf("\n List is empty Cannot Search.");
    } else {
        int Item=getItem();
        for (int i=1;(temp!=NULL);i++) {
            if (temp->Item==Item) {
                InitialPrint();
                printf("%d,", i);
            }
            temp=temp->Next;
        }
        printf("\b  "); 
    }
}

// INSERTION
void Insert_Beginning(){
    Node *NewNode =(Node *)malloc(sizeof(Node));
    NewNode->Item = getItem();
    if (isEmpty()) {
        FirstNode_logic(NewNode);
    } else {
        FirstNodeSwap_logic(NewNode);
    }
}

void Insert_End() {
    int Item=getItem();
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode -> Item = Item;
    if (isEmpty()) {
        FirstNode_logic(NewNode);
    } else {
        LastNode_logic(NewNode);
    }
}

void Insert_Posix() {
    int Posix = getPosix();
    int Item = getItem();
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode -> Item = Item;
    if (isEmpty()) {
        FirstNode_logic(NewNode);
    } else if ((Posix<=0)){
        FirstNodeSwap_logic(NewNode);
    } else {
        Node * temp = First;

        for (int i=1; (i<Posix-1)&&(temp->Next!=NULL);i++) {
            temp = temp -> Next;
        }
        if (temp-> Next == NULL) {
            LastNode_logic(NewNode);
        } else {
            NewNode -> Next = temp -> Next;
            temp -> Next = NewNode;
        }
    }
}

// Deletion
void Delete_Beginning() {
    Node *hold;
    if(isEmpty()) {
        printf("\n Void Deletion. No elements in the list.");
    } else {
        hold = First;
        First=First->Next;
        free(hold);
        if (First == NULL) {
            Last = NULL;
        }
    }
}

void Delete_End() {
    Node *hold, *temp;
    if (isEmpty()) {
        printf("\n Void Deletion. No elements in the list.");
    } else if (First->Next==NULL) { // First Node is the Last Node
        free(First);
        First = NULL;
        Last = NULL;
        return;
    } else {
        DeleteEnd_logic();
    }
}

void Delete_Posix() {
    if(isEmpty()) {
        printf("\n Void Deletion. No elements in the list");
    } else {
        int Posix=getPosix();
        if ((Posix<=1)){
            Delete_Beginning();
        } else {
            Node *hold, *temp = First;
            for (int i=1; (i<Posix-1)&&(temp->Next->Next!=NULL);i++){
                temp = temp -> Next;
            }
            if (temp-> Next->Next == NULL) {
                Delete_End();
            } else {
                hold = temp->Next;
                temp -> Next = hold->Next;
                free(hold);
            }
        }
    }
}

// MENUS SECTION
void Deletion_Menu() {
    int choice=0;
    system("clear");
    printf("\nMENU: Deletion Type\n\n1. Beginning\n2. End\n3. Position (Intuitive)\n\n=>",NodeCount());
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            Delete_Beginning();
            break;
        case 2:
            Delete_End();
            break;
        case 3:
            Delete_Posix();
            break;
        default:
            printf("[ERR 01] Invalid Inputs.");
    }
}

void Insertion_Menu() {
    int choice=0;
    system("clear");
    printf("\nMENU: Insertion Type\n\n1. Beginning\n2. End\n3. Position (Intuitive)\n\n=>",NodeCount());
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            Insert_Beginning();
            break;
        case 2:
            Insert_End();
            break;
        case 3:
            Insert_Posix();
            break;
        default:
            printf("[ERR 01] Invalid Inputs.");
    }
}

void Menu(int *choice) {
    system("clear");
    printf("\nMENU: Current Node Count: %d\n\n1. Insertion\n2. Deletion\n3. Display\n4. Search\n\n=>",NodeCount());
    scanf("%d",choice);
    switch(*choice) {
        case 1:
            Insertion_Menu();
            break;
        case 2:
            Deletion_Menu();
            break;
        case 3:
            system("clear");
            printf("\n The Items are: ");
            Display();
            break;
        case 4:
            Search();
            break;
        case 7: //debug sake hidden
            DEBUG_lastnode();
            break;
        default:
            printf("[ERR 01] Invalid Inputs.");
    }
}

int main() {
    int choice =0;
    do {
        Menu(&choice);
    } while (choice!=0);
}
