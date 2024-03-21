# 🔁 Linear Queue as Linked List
- The [CODE:📑](../Miscellaneous/LinearQueue_LinkedList.c).
- A linear Data Structure.
- Data may be inserted at the end of the Queue and Deleted from the front of the Queue.
- FIFO [First In First Out].

### 🔧 Operations on a Linear Queue:
1. [Enqueue](#enqueue): Adds an element to the rear of the queue.
2. [Dequeue](#dequeue): Removes and returns the element from the front of the queue.
4. [isEmpty](#isempty-check): Checks if the queue is empty.
5. ~~isFull~~: Dynamically Allocated, so there is no need.
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
        NewNode -> Next = NULL;
        if(isEmpty()) {
            First = NewNode;
            Last = NewNode;
        } else {
            Last->Next=NewNode;
            Last=NewNode;
        }
    }
    ```

2. #### **Dequeue**:
    - To delete elements in the queue.
    ```c
    int Dequeue() {
        Node *NewNode = (Node *) malloc (sizeof(Node));
        Node *Hold;
        if (isEmpty()) {
            printf("\n Stack is Empty. Cannot Pop an element.");
        } else {
            Hold = First;
            printf("\n Popped Item: %d",First->Item);
            First=First->Next;
            free(Hold);
        }
    }
    ```

3. #### **Display**:
    - To display the elements in the queue.
    ```c
    void Display() {
        Node *temp = First ;
        printf("\n The Elements in the Stacks are: [ ");
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