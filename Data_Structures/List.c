#include <stdio.h>
#include <stdlib.h>
//#include "./modules/Log.c"
#include "./modules/c_functions_linux.c" //for getch

#define MAXSIZE 30
typedef struct{
    int Item[MAXSIZE];
    int Size;
} List;

void listFill(List *list, int ListIdentifier) {
    printf("\n Enter %d values for the list %d: ",list->Size,ListIdentifier);
    for (int i=0;i<list->Size;i++) {
        scanf("%d",&list->Item[i]);
    }
} 

void InitializeList_each(List *list,int size,int ListIdentifier) {
    list->Size=size;
    listFill(list,ListIdentifier);
}

void InitializeList(List *list,int numberofList) {
    int size=0;
    for (int i=0;i<numberofList;i++) {
        system("clear");
        printf("\n Enter the size of the list %d: ",i+1);
        scanf("%d",&size);
        InitializeList_each(&list[i],size,i+1);
    }
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
    getch();
}

void merge(List *list, int numberofLists) {
    system("clear");
    int chosen[2], temp;
    printf("\nMENU: Choose two lists among");
    for (int i = 0; i < numberofLists; i++) {
        printf("\n%d. List %d", i + 1, i + 1);
    }
    printf("\n\n=>");
    for (int i = 0; i < 2; i++) {
        scanf("%d", &temp);
        chosen[i] = temp - 1;
        //optional for exiting
        if (temp==0) {
            printf("\n[EXIT PROTOCOL] exiting program");
            exit(EXIT_SUCCESS);
        }
    }
    if ((list[chosen[0]].Size + list[chosen[1]].Size) > MAXSIZE) {
        printf("\n [ERR 04] List size will exceed Maximum Allotted value. Aborting...\n");
        exit(EXIT_FAILURE);
    } else {
        for (int i = 0; i < list[chosen[1]].Size; i++) {
            list[chosen[0]].Item[list[chosen[0]].Size + i] = list[chosen[1]].Item[i];
        }
        list[chosen[0]].Size += list[chosen[1]].Size;
    }
}


void menu(List *list,int *choice,int numberofLists) {
    static int ListIdentifier=0;
    system("clear");
    printf("\nMenu:\n\n1. Insert\n2. Delete\n3. Modify\n4. Traverse\n5. Change List");
    if (numberofLists>1) {
        printf("\n6. Merge");
    }
    printf("\n\n=>");
    
    scanf("%d",choice);
    switch(*choice) {
        case 1:
            insertion(&list[ListIdentifier]);
            break;
        case 2:
            deletion(&list[ListIdentifier]);
            break;
        case 3:
            modify(&list[ListIdentifier]);
            break;
        case 4:
            traverse(list[ListIdentifier]);
            break;
        case 5:
            ListIdentifier=(ListIdentifier+1)%numberofLists;
            break;
        case 6:
            if (numberofLists>1) {
                merge(list,numberofLists);
            }
        default:
            printf("\n [ERR 01] Invalid Inputs\n");
            break;
    }
}

int main() {
    int choice=0, numberofLists;

    system("clear"); 
    printf("\n Enter the number of lists: ");
    scanf("%d",&numberofLists);

    List list[numberofLists];

    system("clear");
    InitializeList(&list,numberofLists);
    do {
        menu(&list,&choice,numberofLists);
    } while (choice!=0);
}