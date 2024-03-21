#include <stdio.h>
#include <stdlib.h>
#include "./modules/Log.c"

struct BSTNode {
    int Key;
    struct BSTNode *Left;
    struct BSTNode *Right;
};

typedef struct BSTNode Node;
Node *Root=NULL;
static int alreadycalled=0;

// Modules
int getKey() {
    int Key;
    printf("Enter the Key: ");
    scanf("%d",&Key);
    return Key;
}

int isEmpty(Node *Root) {
    return (Root==NULL);
}

int NodeCount(Node *ParentNode) {
    if (ParentNode==NULL){
        return 0;
    } else {
        return (1+NodeCount(ParentNode->Left)+NodeCount(ParentNode->Right));
    }
}

Node *ParentNodeFind(Node *temp, Node *Child) {
    if (isEmpty(Root)) {
        printf("\n Tree Empty");
        return NULL;
    } else if (isEmpty(temp)) {
        return NULL;
    } else if ((temp->Left==Child)||(temp->Right==Child)) {
        return temp;
    } else if (temp==Child) {//the Element is in the Level 1 condition, right afte the root
        return Root;
    }
    else {
        // Recusively search in the Left Rubtree
        Node *parent = ParentNodeFind(temp->Left, Child);
        if (parent!= NULL) {
            return parent; // If found in Left Subtree, return the parent nodet.
        } 
         // Recursively search in right subtree
        Node *rightParent = ParentNodeFind(temp->Right, Child);
        if (rightParent!= NULL) {
            return rightParent; // If found in right subtree, return the parent node.
        } 
        return NULL; //If Left and Rigth both subtrees are Empty
    }
}

int numberofSiblings(Node *temp) {
    int count=0;
    if (temp->Left!=NULL) {
        count=count++; 
    }
    if (temp->Right!=NULL) {
        count=count++;
    }
    return count;
}

// Insertion
void Insert_Logic(Node **NewNode,int Key) {
    (*NewNode)->Key=Key;
    (*NewNode)->Left=NULL;
    (*NewNode)->Right=NULL;
}

Node *Insert(Node *ParentNode, int Key) {
    if (isEmpty(Root)) {
        Node *NewNode=(Node *)malloc(sizeof(Node));
        Insert_Logic(&NewNode, Key);
        Root=NewNode;
    } else if (Key<ParentNode->Key) {
        if(ParentNode->Left==NULL) {
            Node *NewNode = (Node *)malloc(sizeof(Node));
            Insert_Logic(&NewNode, Key);
            ParentNode->Left=NewNode;
        } else {
            Insert(ParentNode->Left, Key);
        }
    } else {
        if (ParentNode->Right==NULL) {
            Node *NewNode = (Node *)malloc(sizeof(Node));
            Insert_Logic(&NewNode, Key);
            ParentNode->Right=NewNode;
        } else {
            Insert(ParentNode->Right, Key);
        }
    }
}

void Insert_Interface() {
    int Key=getKey();
    Insert(Root, Key);
}

// Search
Node *Search(Node *ParentNode, int Key) { 
    if (isEmpty(Root)) {
        return NULL;
    } else if (Key==ParentNode->Key) {
       return ParentNode;
    } else if(Key<ParentNode->Key) {
        return Search(ParentNode->Left, Key);
    } else {
        return Search(ParentNode->Right, Key);
    }
}

void SearchInterface() {
    int Key =getKey();
    Node *temp=Search(Root,Key);
    if (temp==NULL) {
        printf("\nCouldn't Find the Element in the Tree");
    } else {
        printf("\nElement Found with Parent Node %d and %d siblings",ParentNodeFind(Root,temp)->Key, numberofSiblings(temp));
    }
}

//Deletion
Node *Delete(Node *ParentNode, int Key) {
    printf("\n🚧 Feature Not Implemented.");
    //todo
}

void Delete_Interface() {
    int Key=getKey();
    Delete(Root, Key);
}

// Traversal 
void InitialPrint() {
    if (!alreadycalled) {
        printf("Items Are: ");
        alreadycalled=1;
    } 
}

void PreorderTraversal(Node *ParentNode){
    InitialPrint();
    if (isEmpty(Root)) {
        printf("\n Tree Empty.");
    } else if (!isEmpty(ParentNode)){
        printf("%d, ",ParentNode->Key);
        PreorderTraversal(ParentNode->Left);
        PreorderTraversal(ParentNode->Right);
    }
}

void InorderTraversal(Node *ParentNode){
    InitialPrint();
    if (isEmpty(Root)) {
        printf("\n Tree Empty.");
    } else if (!isEmpty(ParentNode)){
        InorderTraversal(ParentNode->Left);
        printf("%d, ",ParentNode->Key);
        InorderTraversal(ParentNode->Right);
    }
}

void PostorderTraversal(Node *ParentNode){
    InitialPrint();
    if (isEmpty(Root)) {
        printf("\n Tree Empty.");
    } else if (!isEmpty(ParentNode)){
        PostorderTraversal(ParentNode->Left);
        PostorderTraversal(ParentNode->Right);
        printf("%d, ",ParentNode->Key);
    }
}

//Menus
void TraversalMenu() {
    int choice=0;
    alreadycalled=0;
    system("clear");
    printf("\nMENU: Traversal\n\n1. Preorder Traversal\n2. Inorder Traversal\n3. Postorder Traversal\n\n=>");
    scanf("%d",&choice);
    switch(choice) {
        case 1:
            PreorderTraversal(Root);
            break;
        case 2:
            InorderTraversal(Root);
            printf("\b  ");
            break;
        case 3:
            PostorderTraversal(Root);
            printf("\b  ");
            break;
        default:
            printf("\n [ERR] Invalid Option Selected.");
    }
}

void Menu(int *choice) {
    printf("\nMENU: The Number of Nodes: %d\n\n1. Insertion\n2. Deletion🚧\n3. Traversal\n4. Search\n\n=> ", NodeCount(Root));
    scanf("%d",choice);
    switch (*choice) {
        case 1:
            Insert_Interface();
            break;
        case 2:
            Delete_Interface();
            break;
        case 3:
            TraversalMenu();
            break;
        case 4:
            SearchInterface();
            break;
        default:
            printf("\n [ERR] Invalid Option Selected");
    }
}

int main() {
    int choice =0;
    do {
        system("clear");
        Menu(&choice);
    } while (choice!=0);
}