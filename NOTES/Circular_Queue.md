# Introduction
- The [CODE](../Data_Structures/modules/Circular_Queue.c).
- Also called Ring Buffers.
- Data may be inserted at the end of the Queue and Deleted from the front of the Queue.
- FIFO [First In First Out]

## Checks Used
1. **isFull** check:
    - Checking if the Queue is in overflow condition. 
    ```c
    int isFull_Circular(CircularQueue *CQueue) {
        return (CQueue->Front==0 && CQueue->Rear==CQueue->Size-1) || (CQueue->Front==CQueue->Rear+1);
    }
    ```
2. **isEmpty** check: 
    - Checking is the Queue is in underflow condition.
    ```c
    int isEmpty_Circular(CircularQueue *CQueue) {
        return (CQueue->Front==-1 && CQueue->Rear==-1);
    }
    ```

## Methods Used
1. **Initialize** **Queue**: 
    - To set the Front and Rear values of the Queue.
    ```c
    void InitializeQueue_Circular(CircularQueue *CQueue, int size) {
        CQueue->Rear = -1;
        CQueue->Front = -1;
        CQueue->Size=size;
        return;
    }
    ```
2. **Enqueue**:
- To add elements to the Rear of the Queue.
    ```c
    void Enqueue_Circular(CircularQueue *CQueue) {
        int Item;
        printf("\nEnter the Value to be Pushed: ");
        scanf("%d", &Item);

        if (isFull_Circular(CQueue)) {
            printf("\n[ERR 01] Queue is in Overflow Condition.");
            return;
        } 
        if (isEmpty_Circular(CQueue)) {
            ready_Circular(CQueue);
        } else {
            CQueue->Rear=((CQueue->Rear)+1)%(CQueue->Size);
        }
        printf("\nThe Enqueued Value is: %d", Item);
        CQueue->Item[CQueue->Rear] = Item;
    }
    ```

3. **Dequeue**:
    - To delete elements on top of the Queue.
    ```c
    int Dequeue_Circular(CircularQueue *CQueue) {
        if (isEmpty_Circular(CQueue)) {
            printf("\n[ERR 02] Queue is in Underflow Condition. Restarting Queue");
            InitializeQueue_Circular(CQueue,CQueue->Size);
        }
            printf("\nThe Dequeued Value is: %d", CQueue->Item[(CQueue->Front)]);
        if (CQueue->Front==CQueue->Rear) {
            InitializeQueue_Circular(CQueue,CQueue->Size);
        } else {
            CQueue->Front=((CQueue->Front)+1)%(CQueue->Size);
        }
        return CQueue->Item[CQueue->Front-1];
    }
    ```

4. **Display**:
    - To display the elements in the Queue.
    ```c
    void Display_Circular(CircularQueue *CQueue) {
        int debug;
        if (CQueue->Front!=CQueue->Rear) {
            printf("Queue is in Underflow Condition");
        }   
        printf("\nThe Content of the Queue are: [ ");
        if (CQueue->Front<=CQueue->Rear) {
            for (int i = ((CQueue->Front)%(CQueue->Size)); i <= CQueue->Rear; i++) {
                printf("%d,", Peek_Circular(CQueue, i)); // Using Peek_Circular function
            }
        } else {
            for (int i = ((CQueue->Front)%(CQueue->Size)); i != CQueue->Rear; i=(i+1)%(CQueue->Size)) {
                printf("%d,", Peek_Circular(CQueue, i)); // Using Peek_Circular function
            }
            printf("%d,", Peek_Circular(CQueue, CQueue->Rear)); // Using Peek_Circular function
        }
        printf("\b ]");
    }
    ```
