# 🔁 Priority Queue
- The [CODE:📑](../Data_Structures/modules/Priority_Queue.c).
- A linear Data Structure.
- Data may be inserted at the end of the Queue and Deleted from the front of the Queue.
- FIFO [First In First Out].

### 🌿 Types of Priority Queue
1. **Ascending** Priority Queue: 
Where Dequeue operation deletes the smallest value within the Queue.
2. **Descending** Priority Queue:
Where Dequeue operation deletes the largest value withing the Queue.

### 🔧 Operations on a Priority Queue:
1. [Enqueue](#enqueue): Adds an element to the rear of the priority queue.
2. [Dequeue](#dequeue): Removes and returns the element That is either the smallest or the largest depending on the type of priority Queue.
3. [Peek](#peek) (or Front): Returns the element at the front of the priority queue without removing it.
4. [isEmpty](#isempty-check): Checks if the queue is empty.
5. [isFull](#isfull-check): Checks if the queue is full (applicable for fixed-size queues).
6. [find_Maximum's_Position](#find-maximums-position): Find the maximum valued element's position in the queue.
7. [find_Minimum's_Position](#find-minimums-position): Find the minimum valued element's positiong in the queue.
8. [Display](#display): To show the elements of the Queue.

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
1. #### **isFull** check:
    - Checking if the Queue is in overflow condition. 
    ```c
    int isFull(PriorityQueue *PQueue) {
        return (PQueue->Rear == MAX_SIZE - 1);
    }
    ```
2. #### **isEmpty** check: 
    - Checking is the Queue is in underflow condition.
    ```c
    int isEmpty(PriorityQueue *PQueue) {
        return (PQueue->Rear < PQueue->Front);
    }
    ```

### 🛠️ Methods Used
1. #### **Initialize Queue**: 
    - To set the Front and Rear values of the Queue.
    ```c
        void InitializeQueue(PriorityQueue *PQueue) {
        PQueue->Rear = -1;
        PQueue->Front = 0;
        printf("\n[Debug] Initialized at Rear: %d and Front: %d", PQueue->Rear, PQueue->Front);
    }
    ```
2. #### **Enqueue**:
    - To add elements to the Rear of the Queue.
    ```c
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
    ```

3. #### **Dequeue**:
    - To delete the smallest or the largest elements.
    ```c
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
    ```

4. #### **Display**:
    - To display the elements in the queue.
    ```c
    int Peek(PriorityQueue *PQueue, int index) {
        return PQueue->Item[index];
    }

    void Display(PriorityQueue *PQueue) {
        printf("\n[DEBUG] printing with front and rear: %d and %d", PQueue->Front, PQueue->Rear);
        printf("[ ");
        for (int i = PQueue->Front; i <= PQueue->Rear; i++) {
            printf("%d, ", Peek(PQueue, i)); // Using Peek function
        }
        printf("]");
    }
    ```
5. #### **Peek**:
    - To display an element without dequeuing it.
    ```c
    int Peek_Linear(PriorityQueue *PQueue, int index) {
        return PQueue->Item[index];
    }
    ```
    
6. #### **Find Minimum's Position**:
    - To find the position of the smallest valued element in the Queue.
    ```c
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
    ```

7. #### **Find Maximum's Position**:
    - Find the position of the Largest element in the queue.
    ```c
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
    ```