//AVL Tree Balancing
#include <stdio.h>
#include <stdlib.h>
#include "./modules/c_functions_linux.c"

// Data Type Setup
typedef struct node {
    int Item;
    struct node *Left;
    struct node *Right;
    int Height;
} Node;

// Initial Setup
Node *Root=NULL;

// Prototying
Node *Insert(Node *,int);
Node *Delete(Node *, int);
void PreorderTraversal(Node *);
void InorderTraversal(Node *);
void PostorderTraversal(Node *);
Node *rotateRight(Node *);
Node *rotateLeft(Node *);
Node *rotateLeftRight(Node *);
Node *rotateRightLeft(Node *);
int Height(Node *);
int BalanceFactor(Node *);

// Traversal Methods
void PreorderTraversal(Node *node) {
    if (node!=NULL) {
        printf("%d(BF=%d)",node->Item,BalanceFactor(node));
        PreorderTraversal(node->Left);
        PreorderTraversal(node->Right);
    }
}

void InorderTraversal(Node *node) {
    if (node!=NULL) {
        InorderTraversal(node->Left);
        printf("%d(BF=%d)",node->Item,BalanceFactor(node));
        InorderTraversal(node->Right);
    }
}

void PostorderTraversal(Node *node) {
    if (node!=NULL) {
        PostorderTraversal(node->Left);
        PostorderTraversal(node->Right);
        printf("%d(BF=%d)",node->Item,BalanceFactor(node));
    }
}

// Rotations
Node *rotateRight(Node *node) {
    Node *temp;
    temp=node->Left;
    node->Left = temp->Right;
    temp->Right=node;
    node->Height=Height(node);
    temp->Height=Height(temp);
    return temp;
}

Node *rotateLeft(Node *node) {
    Node *temp;
    temp=node->Right;
    node->Right = temp->Left;
    temp->Left=node;
    node->Height=Height(node);
    temp->Height=Height(temp);
    return temp;
}

Node *rotateLeftRight(Node *node) {
    node->Left=rotateLeft(node->Left);
    node = rotateRight(node);
    return node;
}

Node *rotateRightLeft(Node *node) {
    node->Right=rotateRight(node->Right);
    node = rotateLeft(node);
    return node;
}

// Paramaeter calculations 
int Height(Node *node) {
    int LeftHeight, RightHeight;
    if (node==NULL) {
        return 0;
    } 
    // For the Left Node
    if (node->Left==NULL) {
        LeftHeight=0;
    } else {
        LeftHeight=1+(node->Left)->Height;
    } 
    // FOr the Right Node
    if (node->Right==NULL) {
        RightHeight=0;
    } else {
        RightHeight=1+(node->Right)->Height;
    }
    // Final Return
    if (LeftHeight>RightHeight) {
        return(LeftHeight);
    }
    return (RightHeight);
}

int BalanceFactor(Node *node) {
    int LeftHeight, RightHeight;
    if (node=NULL) {
        return 0;
    }

    // For the Left
    if (node->Left==NULL) {
        LeftHeight=0;
    } else {
        LeftHeight=1+(node->Left)->Height;
    }

    // FOr the Right
    if (node->Right==NULL) {
        RightHeight=0;
    } else {
        RightHeight=1+(node->Right)->Height;
    }
    //Final
    return (LeftHeight-RightHeight);
}

// Deletion
Node *Delete(Node *node, int Item) {
    Node *temp;
    if (node==NULL) {
        return NULL;
    } else {
        if (Item > node->Item) {
            node->Right=Delete(node->Right,Item);
            if (BalanceFactor(node)==-2) {
                if (BalanceFactor(node->Left)>=0) {
                    node = rotateLeft(node);
                } else {
                    node = rotateLeftRight(node);
                }
            }
        } else if (Item < node->Item) {
            node -> Left = Delete(node->Left, Item);
            if (BalanceFactor(node)==-2) { //check this part
                if (BalanceFactor(node->Right)<=0) {
                    node = rotateRight(node);
                } else {
                    node = rotateRightLeft(node);
                }
            }
        } else { // data is found   
            if (node->Right!=NULL) {
                temp=node->Right;
                while (temp->Left!=NULL) {
                    temp=temp->Left;
                } 
                node->Item=temp->Item;
                node->Right=Delete(node->Right, temp->Item);
                if(BalanceFactor(node)==2) {
                    if (BalanceFactor(node->Left)>=0)  {
                        node = rotateLeft(node);
                    } else {
                        node = rotateLeftRight(node);
                    }
                }
            } else {
                return (node->Left);
            } 
            node->Height=Height(node);
            return(temp);
        }
    }
}

void Delete_Interface() {
    int Item;
    printf("\n Enter the Element to Delete: ");
    scanf("%d",&Item);
    Delete(Root, Item);
}

// Insertion
Node *Insert(Node *node, int Item) {
    if (node==NULL) { // Empty tree condition
        node=(Node *)malloc(sizeof(Node));
        node->Item=Item;
        node->Left=NULL;
        node->Right=NULL;
    } else {
        if (Item > node->Item) {
            node->Right = Insert(node->Right, Item);
            if (BalanceFactor(node)==-2) {
                if(Item > (node->Right)->Item) {
                    node = rotateRight(node);
                } else {
                    node = rotateRightLeft(node);
                }
            } else {
                if (Item < node->Item) {
                    node->Left = Insert(node->Left, Item);
                    if(BalanceFactor(node)==2) {
                        if(Item < (node->Left)->Item) {
                            node = rotateLeft(node);
                        } else {
                            node = rotateLeftRight(node);
                        }
                    }
                } 
            }
        }
        node->Height=Height(node);
        return node;
    }
}
    
void Insert_Interface() {
    int Item;
    printf("\n Insert the Element to Insert: ");
    scanf("%d",&Item);
    Insert(Root, Item);
}

// Creation 
void Create() {
    int InitialSize, tempItem;
    printf("Enter the Number of Elements: ");
    scanf("%d",&InitialSize);
    printf("Enter the Data: ");
    for (int i=0;i<InitialSize;i++) {
        scanf("%d",&tempItem);
        Insert(Root,tempItem);
    }
}

// Menus
void TraverseMenu() {
    int choice;
    printf("\nMENU: Traverse\n1. Preorder Traversal\n2. Inorder Traversal\n3. Postorder Traversal\n4. Back\n\n=> ");
    scanf("%d",&choice);
    system("clear");
    switch(choice) {
        case 1:
            PreorderTraversal(Root);
            getch();
            break;
        case 2:
            InorderTraversal(Root);
            getch();
            break;
        case 3:
            PostorderTraversal(Root);
            getch();
            break;
        case 4:
            break;
        default:
            printf("\nInvalid Input");
    }
}

void Menu(int *choice) {
    printf("\nMENU\n\n1. Create\n2. Insert\n3. Delete\n4. Traverse\n5. Quit\n\n=> ");
    scanf("%d",choice);
    switch (*choice) {
        case 1: 
            Create();
            break;
        case 2:
            Insert_Interface();
            break;
        case 3:
            Delete_Interface();
            break;
        case 4:
            TraverseMenu();
            break;
        case 5:
            exit(EXIT_FAILURE);
    }
}

int main() {
    int choice=5;
    do {
        system("clear");
        Menu(&choice);
    } while (choice != 5);
}