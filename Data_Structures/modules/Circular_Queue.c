#define MAX_SIZE 50
//#include "./Log.c"

typedef struct { 
    int Item[MAX_SIZE];
    int Front;
    int Rear;
    int Size;
} CircularQueue;

void InitializeQueue_Circular(CircularQueue *CQueue, int size) {
    CQueue->Rear = -1;
    CQueue->Front = -1;
    CQueue->Size=size;
    return;
}

void ready_Circular(CircularQueue *CQueue) {
    CQueue->Rear = 0;
    CQueue->Front = 0;   
}

int isFull_Circular(CircularQueue *CQueue) {
    return (CQueue->Front==0 && CQueue->Rear==CQueue->Size-1) || (CQueue->Front==CQueue->Rear+1);
}

int isEmpty_Circular(CircularQueue *CQueue) {
    return (CQueue->Front==-1 && CQueue->Rear==-1);
}

void Enqueue_Circular(CircularQueue *CQueue) {
    int Item;
    //writeLog("\n[ENQUEUE] Enqueue Triggered with Front: %d and Rear: %d", CQueue->Front,CQueue->Rear);

    printf("\nEnter the Value to be Pushed: ");
    scanf("%d", &Item);

    if (isFull_Circular(CQueue)) {
        printf("\n[ERR 01] Queue is in Overflow Condition.");
        //writeLog("\n[TRIGGERS] Overflow Triggered");
        return;
    } 
    if (isEmpty_Circular(CQueue)) {
        ready_Circular(CQueue);
    } else {
        CQueue->Rear=((CQueue->Rear)+1)%(CQueue->Size);
    }
    printf("\nThe Enqueued Value is: %d", Item);
    //writeLog("\n[ENQUEUE]  Enqueue after Triggered with Front: %d and Rear: %d and value: %d", CQueue->Front,CQueue->Rear,Item);
    CQueue->Item[CQueue->Rear] = Item;
}

int Dequeue_Circular(CircularQueue *CQueue) {
    //writeLog("\n[DEQUEUE]  Dequeue Triggered with Front: %d and Rear: %d", CQueue->Front,CQueue->Rear);
    if (isEmpty_Circular(CQueue)) {
        printf("\n[ERR 02] Queue is in Underflow Condition. Restarting Queue");
        //writeLog("\n[TRIGGERS] Underflow Triggered");
        InitializeQueue_Circular(CQueue,CQueue->Size);
    }
        //writeLog("\n[DEQUEUE]  Dequeue after Triggered with Front: %d and Rear: %d and value: %d", CQueue->Front,CQueue->Rear,CQueue->Item[(CQueue->Front)]);
        printf("\nThe Dequeued Value is: %d", CQueue->Item[(CQueue->Front)]);
    if (CQueue->Front==CQueue->Rear) {
        InitializeQueue_Circular(CQueue,CQueue->Size);
    } else {
        CQueue->Front=((CQueue->Front)+1)%(CQueue->Size);
    }
    return CQueue->Item[CQueue->Front-1];
}

int Peek_Circular(CircularQueue *CQueue, int index) {
    return CQueue->Item[index];
}

void Display_Circular(CircularQueue *CQueue) {
    int debug;
    if (CQueue->Front!=CQueue->Rear) {
        printf("Queue is in Underflow Condition");
        //writeLog("\n[TRIGGERS] Underflow Condition Triggered");
    }   
    printf("\nThe Content of the Queue are: [ ");
    if (CQueue->Front<=CQueue->Rear) {
        for (int i = ((CQueue->Front)%(CQueue->Size)); i <= CQueue->Rear; i++) {
            //writeLog("\n[DISPLAY]  Display mini triggered with i: %d and Rear: %d value:%d", i,CQueue->Rear,Peek_Circular(CQueue, i));
            printf("%d,", Peek_Circular(CQueue, i)); // Using Peek_Circular function
        }
    } else {
        for (int i = ((CQueue->Front)%(CQueue->Size)); i != CQueue->Rear; i=(i+1)%(CQueue->Size)) {
            //writeLog("\n[DISPLAY] Display mini triggered with i: %d and Rear: %d value:%d", i,CQueue->Rear,Peek_Circular(CQueue, i));
            printf("%d,", Peek_Circular(CQueue, i)); // Using Peek_Circular function
        }
        printf("%d,", Peek_Circular(CQueue, CQueue->Rear)); // Using Peek_Circular function
    }
    printf("\b ]");
    //writeLog("\n");
}

void menu_CircularQueue(CircularQueue *CQueue, int *choice) {
    printf("\nMENU:\n\n1. Enqueue\n2. Dequeue\n3. Display\n\n=> ");
    scanf("%d", choice);
    switch (*choice) {
        case 1:
            Enqueue_Circular(CQueue);
            break;
        case 2:
            Dequeue_Circular(CQueue);
            break;
        case 3:
            Display_Circular(CQueue);
            break;
        default:
            printf("\n[ERR 03]: Enter a Valid Option");
            break;
    }
}

void CircularQueue_Interface() {
    system("clear");
    CircularQueue CQueue;
    int choice = 0,size;

    printf("Enter the size of the Queue: ");
    scanf("%d",&size);
    InitializeQueue_Circular(&CQueue,size);

    do {
        system("clear");
        menu_CircularQueue(&CQueue, &choice);
    } while (choice != 0);
    //writeLog("\n------------------------------------END------------------------------------\n\n");
}