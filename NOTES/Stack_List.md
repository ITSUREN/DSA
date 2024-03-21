# 📦 Stack as List
- The [CODE:📑](../Data_Structures/stack.c).
- A linear Data Structure.
- A special type of [List](./List.md).
- Data may be inserted and deleted only of the top of the stack. 
- LIFO [Last In First Out]

### 🔧 Operations on a Stack:
1. [Push](#push): Adds an element to the top of the Stack.
2. [Pop](#pop): Returns and deletes an item fromt eh top of the Stack.
4. [isEmpty](#isempty-check): Checks if the queue is empty.
5. [isFull](#isfull-check): Checks if the queue is full (applicable for fixed-size queues).
6. [Traverse](#traverse): Displays the content of the Stack.

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
1. #### **isFull** check:
    - Checking if the stack is in overflow condition. 
    ```c
    if ((Stacks->top) == (MAX_SIZE-1)) {
        printf("\n[Warn 02]: Stack Full.");
        return 1;
    } else {
         return 0;
    }
    ```
2. #### **isEmpty** check: 
    - Checking is the stack is in underflow condition.
    ```c
    if ((Stacks->top)==-1) {
        printf("\n[Warn 01]: Stack Empty.");
        return 1;
    } else {
        return 0;
    }
    ```

### 🛠️ Methods Used
1. #### **Initialize** **Stack**: 
    - To set the Top of the stack to -1.
    ```c
    void InitializeStack(stack *Stacks){
        (Stacks->top)=-1;
    }
    ```
2. #### **Push**:
    - To add elements to the top of the stack.
    ```c
    void push(stack *Stacks) {
        int data;
        printf("\nEnter the Data to be pushed: ");
        scanf("%d",&data);
        if (!isFull(Stacks)) {
            (Stacks->top)++;
            (Stacks->data)[Stacks->top]=data;
        } else {
            printf("\n[ERR 01]: Aborted because the stack was full");
            exit(EXIT_FAILURE);
        }
    }
    ```

3. #### **Pop**:
    - To delete elements on top of the stack.
    ```c
    int pop(stack *Stacks) {
        if (!isEmpty(Stacks)) {
            int val=(Stacks->data)[Stacks->top];
            printf("\nData Popped: %d",val);
            (Stacks->top)--;
            return val;
        } else {
            printf("\n[ERR 02]: Aborted because the stack was empty");
            exit(EXIT_FAILURE);
        }
    }
    ```

4. #### **Traverse**:
    - To display the elements in the stack.
    ```c
    void traverse(stack *Stacks) {
        printf("\n The Elements in the Stacks are: [ ");
        for (int i=0;i<=Stacks->top;i++) {
            printf("%d,",(Stacks->data)[i]);
        }
        printf("\b ]\b");
    }
    ```