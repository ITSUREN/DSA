# 📜 List
- The [CODE:📑](../Data_Structures/List.c).
- A homogenous set of elements or objects.
- Insertion, Deletion and Access can be done at any point on the list.
- Each element has an order i.e Index.

### 🔧 Operations on a List:
1. **[Insertion](#insertion)**: Adds an element to a position in the List.
2. **[Deletion](#deletion)**: Removes and element from a position in the List.
3. **[Modification](#deletion)**: Change the Value of an element in certain position in the List.
4. **[inRange](#in-range-check)**: Checks if the list is empty.
5. **[Traversing](#traversing)**: Displays the elements in the list
6. **[Merging](#merging)**: Mergest Two Lists

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
1. #### **In Range** check:
- checks whether the Index is withing the size of the list.
```c
int inRange(List list,int index){
    return ((index>=0) && (index<list.Size));
}
```

### 🛠️ Methods Used
1. #### **Initialize List**: 
- Initializes all the Lists.
```c
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
```
2. #### **Shifter***:
- Shifts the elements from index position right or left.
```c
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
```

3. #### **Insertion**:
- Inserts new element to the list:
```c
oid insertion(List *list){
    int Item;
    int index=getIndex(*list);
    printf("\n Enter the Value to Insert: ");
    scanf("%d",&Item);
    shifter(list, index, 2);
    list->Item[index]=Item;
}
```

4. #### **Deletion**:
- Deletes an element from list.
```c
void deletion(List *list) {
    int index=getIndex(*list);
    shifter(list, index, 1);
}
```
5. #### **Modification**:
- Modifies the element in the list.
```c
void modify(List *list){
    int index=getIndex(*list),NewItem;
    printf("\n Enter the New Value: ");
    scanf("%d",&NewItem);
    list->Item[index]=NewItem;
}
```

6. #### **Traversing**:
- Displays the list.
```c
void traverse(List list){
    printf("\n The Items in the list are: [ ");
    for (int i=0;i<list.Size;i++) {
        printf("%d,",list.Item[i]);
    }
    printf("\b ]");
    getch();
}
```
7. #### **Merging**:
- Merges two lists.
```c
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
```
