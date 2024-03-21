# 🔁 Linear Queue as List
- The [CODE:📑](../Data_Structures/modules/Linear_Queue.c).
- A linear Data Structure.
- Data may be inserted at the end of the Queue and Deleted from the front of the Queue.
- FIFO [First In First Out].

### 🔧 Operations on a Linear Queue:
1. [Enqueue](#enqueue): Adds an element to the rear of the queue.
2. [Dequeue](#dequeue): Removes and returns the element from the front of the queue.
3. [Peek](#peek) (or Front): Returns the element at the front of the queue without removing it.
4. [isEmpty](#isempty-check): Checks if the queue is empty.
5. [isFull](#isfull-check): Checks if the queue is full (applicable for fixed-size queues).
6. [Display](#display): To show the elements of the Queue.

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
1. #### **isFull** check:
    - Checking if the Queue is in overflow condition. 
    ```c
    int isFull(LinearQueue *LQueue) {
        return (LQueue->Rear == MAX_SIZE - 1);
    }
    ```
2. #### **isEmpty** check: 
    - Checking is the Queue is in underflow condition.
    ```c
    int isEmpty(LinearQueue *LQueue) {
        return (LQueue->Rear < LQueue->Front);
    }
    ```

### 🛠️ Methods Used
1. #### **Initialize** **Queue**: 
    - To set the Front and Rear values of the Queue.
    ```c
        void InitializeQueue(LinearQueue *LQueue) {
        LQueue->Rear = -1;
        LQueue->Front = 0;
        printf("\n[Debug] Initialized at Rear: %d and Front: %d", LQueue->Rear, LQueue->Front);
    }
    ```
2. #### **Enqueue**:
    - To add elements to the Rear of the Queue.
    ```c
    void Enqueue(LinearQueue *LQueue) {
        int Item;
        printf("\nEnter the Value to be Pushed: ");
        scanf("%d", &Item);
        if (isFull(LQueue)) {
            printf("\n[ERR 01] Queue is in Overflow Condition.");
            exit(EXIT_FAILURE);
        } else {
            LQueue->Item[++(LQueue->Rear)] = Item;
        }
    }
    ```

3. #### **Dequeue**:
    - To delete elements in the queue.
    ```c
    int Dequeue(LinearQueue *LQueue) {
        if (isEmpty(LQueue)) {
            printf("\n[ERR 02] Queue is in Underflow Condition");
            exit(EXIT_FAILURE);
        } else {
            return LQueue->Item[(LQueue->Front)++];
        }
    }
    ```

4. #### **Display**:
    - To display the elements in the queue.
    ```c
    int Peek(LinearQueue *LQueue, int index) {
        return LQueue->Item[index];
    }

    void Display(LinearQueue *LQueue) {
        printf("\n[DEBUG] printing with front and rear: %d and %d", LQueue->Front, LQueue->Rear);
        printf("[ ");
        for (int i = LQueue->Front; i <= LQueue->Rear; i++) {
            printf("%d, ", Peek(LQueue, i)); // Using Peek function
        }
        printf("]");
    }
    ```
5. #### **Peek**:
    - To display an element without dequeuing it.
    ```c
    int Peek_Linear(LinearQueue *LQueue, int index) {
        return LQueue->Item[index];
    }
    ```