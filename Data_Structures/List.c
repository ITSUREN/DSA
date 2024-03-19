#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30

typedef struct{
    int Item[MAXSIZE];
    int Size;
} List;

void listFill(List *list) {
    printf("\n Enter %d values for the list: ");
    for (int i=0;i<list->Size;i++) {
        scanf("%d",&list->Item[i]);
    }
} 

void InitializeList(List *list,int size) {
    list->Size=size;
    listFill(list);

}

int inRange(List list,int index){
    return ((index>=0) && (index<list.Size));
}

int getIndex(List list) {
    int index=0;
    do {
        printf("\n Enter the index: ");
        fflush(stdin);
        scanf("%d",&index);

        if(!inRange(list,index)) {
        printf("\n [ERR 03] Index not within Range. Try again.\n");
        }
    } while(!inRange(list,index));
    return index;
}

int shifter(List *list,int index,int direction) {
    switch(direction) {
        case 1: //left 
            for (int i=index;i<list->Size-1;i++) {
                list->Item[i]=list->Item[i+1];
            }
            list->Size--;
            break;
        case 2: //right
            for (int i=list->Size;i>index;i--) {
                list->Item[i]= list->Item[i-1];
            }
            list->Size++;
            break;
        default:
            printf("\n[ERR 01] (Internal Error) Unexpected value for direction passed\n");
            exit(EXIT_FAILURE);
    }
}

void insertion(List *list){
    int Item;
    int index=getIndex(*list);
    printf("\n Enter the Value to Insert: ");
    scanf("%d",&Item);
    shifter(list, index, 2);
    list->Item[index]=Item;
}

void deletion(List *list) {
    int index=getIndex(*list);
    shifter(list, index, 1);
}

void modify(List *list){
    int index=getIndex(*list),NewItem;
    printf("\n Enter the New Value: ");
    scanf("%d",&NewItem);
    list->Item[index]=NewItem;
}

void traverse(List list){
    printf("\n The Items in the list are: [ ");
    for (int i=0;i<list.Size;i++) {
        printf("%d,",list.Item[i]);
    }
    printf("\b ]");
}

List *merging(List *list1, List *list2) {
    //todo
}

void menu(List *list,int *choice) {
    system("clear");
    printf("\nMenu:\n\n1. Insert\n2. Delete\n3. Modify\n4. Traverse\n\n=>");
    scanf("%d",choice);
    switch(*choice) {
        case 1:
            insertion(list);
            break;
        case 2:
            deletion(list);
            break;
        case 3:
            modify(list);
            break;
        case 4:
            traverse(*list);
            break;
        default:
            printf("\n [ERR 01] Invalid Inputs\n");
            break;
    }
}

int main() {
    List list;
    int size,choice=0;
    system("clear");
    printf("\n Enter the size of the list: ");
    scanf("%d",&size);
    InitializeList(&list,size);
    do {
        menu(&list,&choice);
    } while (choice!=0);
}