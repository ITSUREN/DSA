#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

struct Node_SL{
    int Item;
    struct Node_SL *Next;
};

typedef struct Node_SL Node;

Node *First=NULL;
Node *Last=NULL;

int  getItem() {
    int Item;
    printf("\nEnter the Element to Insert: ");
    scanf("%d", &Item);
    return Item;
}

int getPosix() {
    int Posix;
    printf("\nEnter the Position: ");;
    scanf("%d",&Posix);
    return Posix;
}

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
    NewNode->Next= First; // Point to Whichever Node the First pointer points to 
    First = NewNode;
}

void Insert_Beginning(){
    Node *NewNode =(Node *)malloc(sizeof(Node));
    NewNode->Item = getItem(); //get the Item
    if (First==NULL) {
        FirstNode_logic(NewNode);
    } else {
        FirstNodeSwap_logic(NewNode);
    }
}

void Insert_End() {
    int Item=getItem();
    Node *NewNode = (Node *)malloc(sizeof(Node));
    NewNode -> Item = Item;
    if (First==NULL) {
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
    if ((First==NULL)) {
        FirstNode_logic(NewNode);
    } else if ((Posix==0)){
        FirstNodeSwap_logic(NewNode);
    } else {
        Node * temp = First; //initially begin with the Fist Node 0

        // Reach to a Node Position one less than the passed Node n-1
        for (int i=1; (i<Posix-1)&&(temp->Next!=NULL);i++) {
            temp = temp -> Next; // Move onto the next, stop at 2 lesser because temp will make it effectively 1 lesser
        }
        if (temp-> Next == NULL) {
            LastNode_logic(NewNode);
        } else {
            NewNode -> Next = temp -> Next; // The One that was in the position
            temp -> Next = NewNode; // n-1 points to n(the NewNode)
        }
    }
}

int NodeCount() {
    Node *temp = First;
    int NodeCount=0;
    while (temp!=NULL) {
        NodeCount++;
        temp = temp->Next;
    } 
    return NodeCount;
}

void  Display() {
    Node *temp = First;
    
    printf("[ ");
    while (temp!=NULL) {
        printf("%d,",temp->Item);
        temp = temp->Next;
    } 
    printf("\b ]");
}

void Delete_Beginning() {
    //todo
}

void Delete_End() {
    //todo
}

void Delete_Posix() {
    //todo
}

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
    printf("\nMENU: Current Node Count: %d\n\n1. Insertion\n2. Deletion\n3. Display\n\n=>",NodeCount());
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