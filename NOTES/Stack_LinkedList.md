# 📦 Stack as Linked List
- The [CODE:📑](../Miscellaneous/Stack_LinkedList.c).
- A linear Data Structure.
- A special type of [LinkedList](./Linked_List.md).
- Data may be inserted or deleted only on the top of the stack. 
- LIFO [Last In First Out].

### 🔧 Operations on a Stack:
1. [Push](#push): Adds an element to the top of the Stack.
2. [Pop](#pop): Returns and deletes an item from the top of the Stack.
4. [isEmpty](#isempty-check): Checks if the queue is empty.
5. ~~isFull~~: Dynamically Allocated Memory, hence, not needed.
6. [Traverse](#traverse): Displays the contents of the Stack.

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
1. #### **isEmpty** check: 
    - Checking is the stack is in underflow condition.
    ```c
    int isEmpty() {
        return (Top==NULL);
    }
    ```

### 🛠️ Methods Used
1. #### **Push**:
    - To add elements to the top of the stack.
    ```c
    void push() {
        Node *NewNode = (Node *) malloc (sizeof(Node));
        int Item=getItem();
        NewNode -> Item = Item;
        NewNode -> Next = NULL;
        if(isEmpty()) {
            Top = NewNode;
        } else {
            NewNode->Next=Top;
            Top = NewNode; 
        }
    }
    ```

2. #### **Pop**:
    - To delete elements from the top of the stack.
    ```c
    int pop() {
        Node *NewNode = (Node *) malloc (sizeof(Node));
        Node *Hold;
        if (isEmpty()) {
            printf("\n Stack is Empty. Cannot Pop an element.");
        } else {
            Hold = Top;
            printf("\n Popped Item: %d",Top->Item);
            Top=Top->Next;
            free(Hold);
        }
    }
    ```

3. #### **Traverse**:
    - To display the elements in the stack.
    ```c
    void traverse() {
        Node *temp = Top;
        printf("\n The Elements in the Stacks are: [ ");
        if (!isEmpty()) {
            for (int i=0;temp->Next!=NULL;i++) {
                printf("%d,",temp->Item);
                temp=temp->Next;
            }
            printf("%d,",temp->Item);
        }
        printf("\b ]\b");
    }
    ```
