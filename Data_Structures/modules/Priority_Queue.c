#define MAX_SIZE 50

typedef struct { 
    int Item[MAX_SIZE];
    int Front;
    int Rear;
    int Size;
} PriorityQueue;

void InitializeQueue_Priority(PriorityQueue *PQueue, int size) {
    PQueue->Rear = -1;
    PQueue->Front = 0;
    PQueue->Size=size;
}

int isFull_Priority(PriorityQueue *PQueue) {
    return (PQueue->Rear == PQueue->Size - 1);
}

int isEmpty_Priority(PriorityQueue *PQueue) {
    return (PQueue->Rear < PQueue->Front);
}

int findMin_posix(PriorityQueue *PQueue) {
    int Smallest=PQueue->Item[PQueue->Front],index=0;
    for (int i=PQueue->Front+1;i<=PQueue->Rear;i++) {
        if (PQueue->Item[i]<Smallest) {
            index=i;
            Smallest=PQueue->Item[i];
        }
    }
    return index;
}

int findMax_posix(PriorityQueue *PQueue) {
    int Largest=PQueue->Item[PQueue->Front],index=0;
    for (int i=PQueue->Front+1;i<=PQueue->Rear;i++) {
        if (PQueue->Item[i]>Largest) {
            index=i;
            Largest=PQueue->Item[i];
        }
    }
    return index;
}

void PriorityQueue_Reformatter(PriorityQueue *PQueue, int index) {
    for (int i=index;i<PQueue->Rear;i++) {
        PQueue->Item[i]=PQueue->Item[i+1];
    }
    PQueue->Rear--;
}

void Enqueue_Priority(PriorityQueue *PQueue) {
    int Item;
    printf("\nEnter the Value to be Pushed: ");
    scanf("%d", &Item);
    if (isFull_Priority(PQueue)) {
        printf("\n[ERR 01] Queue is in Overflow Condition.");
        exit(1);//Exit Failure
    } else {
        printf("\nThe Enqueued Value is: %d", Item);
        PQueue->Item[++(PQueue->Rear)] = Item;
    }
}

int Dequeue_Priority(PriorityQueue *PQueue, int type) {
    int index;
    if (isEmpty_Priority(PQueue)) {
        printf("\n[ERR 02] Queue is in Underflow Condition");
        exit(1); //Exit Failure
    } else {
        switch (type) {
            case 1:
                index=findMin_posix(PQueue);
                break;
            case 2:
                index=findMax_posix(PQueue);
                break;
            default:
                printf("\n [ERR 03] Invalid Type for Priority Queue Passed.");
                break;
        }
        PriorityQueue_Reformatter(PQueue,index);
        return PQueue->Item[index];  
    }
}

int Peek_Priority(PriorityQueue *PQueue, int index) {
    return PQueue->Item[index];
}

void Display_Priority(PriorityQueue *PQueue) {
    printf("\nThe Content of the Queue are: [ ");
    for (int i = PQueue->Front; i <= PQueue->Rear; i++) {
        printf("%d,", Peek_Priority(PQueue, i)); // Using Peek_Priority function
    }
    printf("\b ]");
}

void menu_PriorityQueue(PriorityQueue *PQueue, int *choice, int type) {
    printf("\nMENU: Operations\n\n1. Enqueue\n2. Dequeue\n3. Display\n\n=> ");
    scanf("%d", choice);
    switch (*choice) {
        case 1:
            Enqueue_Priority(PQueue);
            break;
        case 2:
            Dequeue_Priority(PQueue,type);
            break;
        case 3:
            Display_Priority(PQueue);
            break;
        default:
            printf("\n[ERR 03]: Enter a Valid Option");
            break;
    }
}

void menu_PriorityQueue_Type(PriorityQueue *PQueue) {
    int type, choice=0;
    printf("\nMENU: Select the Type of Priority Queue.\n\n1. Ascending Priority Queue\n2. Descending Priority Queue\n\n=> ");
    scanf("%d",&type);
    do {
        system("clear");
        menu_PriorityQueue(PQueue, &choice,type);
    } while (choice != 0);
}

void PriorityQueue_Interface() {
    system("clear");
    PriorityQueue PQueue;
    int choice = 0,size;

    printf("Enter the size of the Queue: ");
    scanf("%d",&size);
    InitializeQueue_Priority(&PQueue,size);
    menu_PriorityQueue_Type(&PQueue);
}