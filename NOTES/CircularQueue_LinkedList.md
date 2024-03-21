# 🔁 Circular Queue as Linked List
- The [CODE:📑](../Miscellaneous/CircularQueue_LinkedList.c).
- Also called Ring Buffers.
- Data may be inserted at the end of the Queue and Deleted from the front of the Queue.
- FIFO [First In First Out].

### 🔧 Operations on a Circular Queue:
1. [Enqueue](#enqueue): Adds an element to the rear of the queue.
2. [Dequeue](#dequeue): Removes and returns the element from the front of the queue.
4. [isEmpty](#isempty-check): Checks if the queue is empty.
5. ~~isFull~~: Dynamically Allocated, so no need.
6. [Display](#display): To show the elements of the Queue.

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
1. #### **isEmpty** check: 
    - Checking is the Queue is in underflow condition.
    ```c
    int isEmpty() {
        return (First==NULL);
    }
    ```

### 🛠️ Methods Used
1. #### **Enqueue**:
- To add elements to the Rear of the Queue.
    ```c
    void Enqueue() {
        Node *NewNode = (Node *) malloc (sizeof(Node));
        int Item=getItem();
        NewNode -> Item = Item;
        if(isEmpty()) {
            NewNode -> Next = NewNode;
            First = NewNode;
            Last = NewNode;
        } else {
            NewNode -> Next = First;
            Last->Next=NewNode;
            Last=NewNode;
        }
    }

    ```

2. #### **Dequeue**:
    - To delete elements from the Queue.
    ```c
    int Dequeue() {
        Node *NewNode = (Node *) malloc (sizeof(Node));
        Node *Hold;
        if (isEmpty()) {
            printf("\n Stack is Empty. Cannot Pop an element.");
        } else if (First == Last) {
            First = NULL;
            Last = NULL;
        } else {
            Hold = First;
            printf("\n Popped Item: %d",First->Item);
            First=First->Next;
            Last->Next=First;
            free(Hold);
        }
    }
    ```

3. #### **Display**:
    - To display the elements in the Queue.
    ```c
    void Display() {
        Node *temp = First ;
        printf("\n The Elements in the List are: [ ");
        if (!isEmpty()) {
            for (int i=0;temp!=Last;i++) {
                printf("%d,",temp->Item);
                temp=temp->Next;
            }
            printf("%d,",Last->Item);
        }
        printf("\b ]\b");
    }
    ```
