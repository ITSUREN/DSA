# 🔗 Singly Linked List
- The [CODE:📑](../Data_Structures/SinglyLinked_List.c).
- Has only One Structural pointer

### 🔧 Operations on a Linked List:
1. **[Inserting Elements](#insertions)**
    - [Inserting an Element at the Beginning](#inserting-at-the-beginning)
    - [Inserting an Element at the End](#inserting-at-the-end)
    - [Insserting an Element at a Specified position](#inserting-at-a-position-intuitive)
2. **[Deleting Elements](#deletion)**
    - [Deleting an Element at the Beginning](#deletion-at-the-beginning)
    - [Deleting an Element at the End](#deletion-at-the-end)
    - [Deleting an Element at ts Specified Position](#deletion-at-the-end)
3. **[Counting number of Nodes](#node-count)**
4. **[Displaying Nodes](#display)**
5. **[Searching a Node](#search)**
6. Merging Linked List (WILL DO LATER)

&nbsp;
# 🧩 **Operations**
## ✔️ Logics Used
1. #### **First Node** logic:
    - Logic used when there is no node in the Linked List.
    ```c
    void FirstNode_logic(Node *NewNode) {
        NewNode -> Next = NULL;
        First = NewNode;
        Last = NewNode;
    }
    ```
2. #### **First Node Swap** Logic:
    - Logic used when the first node already exist be writing must be done.
    ```c
    void FirstNodeSwap_logic(Node *NewNode) {
        NewNode->Next= First; 
        First = NewNode;
    }
    ```
3. #### **Last Node** Logic: 
    - Logic used when appending Nodes to the Linked List.
    ```c
    void LastNode_logic(Node *NewNode) {
        NewNode -> Next = NULL;
        Last -> Next = NewNode; 
        Last = NewNode;
    }
    ```
4. #### **Delete Last** Logic:
    - To delete the last Nodes of the Linked List.
    ```c
    void DeleteEnd_logic() {
        Node *temp = First;
        while (temp->Next->Next != NULL) { // Traverse to the second last node
            temp = temp->Next;
        }
        free(temp->Next); // Free the last node
        temp->Next = NULL; // Set the next pointer of second last node to NULL
        Last = temp; // Update the Last pointer to point to the second last node
    }
    ```

## 🛠️ Methods Used
1. ### **Insertions**: 
- To Insert nodes to the Linked List.
     1. #### Inserting at the beginning
     - To insert at the Beginning of the Linked List.
     ```c
     void Insert_Beginning(){
        Node *NewNode =(Node *)malloc(sizeof(Node));
        NewNode->Item = getItem(); //get the Item
        if (First==NULL) {
            FirstNode_logic(NewNode);
        } else {
            FirstNodeSwap_logic(NewNode);
        }
    }
    ```
    2. #### Inserting at the end
    - To insert at the End of the Linked List.
    ```c
    void Insert_End() {
        int Item=getItem();
        Node *NewNode = (Node *)malloc(sizeof(Node));
        NewNode -> Item = Item;
        if (First==NULL) {
            FirstNode_logic(NewNode);
        } else {
            LastNode_logic(NewNode);
        }
    }
    ```
    3. #### Inserting at a Position (INTUITIVE)
    - Insert anywhere in the List
    - Will Resolve in cases of Beginning and Ending Insertion inferred throgh Posix
    ```c
    void Insert_Posix() {
        int Posix = getPosix();
        int Item = getItem();
        Node *NewNode = (Node *)malloc(sizeof(Node));
        NewNode -> Item = Item;
        if ((First==NULL)) {
            FirstNode_logic(NewNode);
        } else if ((Posix==0)){
            FirstNodeSwap_logic(NewNode);
        } else {
            Node * temp = First; 
            for (int i=1; (i<Posix-1)&&(temp->Next!=NULL);i++) {
                temp = temp -> Next; 
            }
            if (temp-> Next == NULL) {
                LastNode_logic(NewNode);
            } else {
                NewNode -> Next = temp -> Next; 
                temp -> Next = NewNode; 
            }
        }
    }
    ```

2. ### **Deletion**:
- To Delete Nodes from the Linked List.
    1. #### Deletion at the beginning
     - To Delete at the Beginning of the Linked List.
     ```c
    void Delete_Beginning() {
        Node *hold;
        if(isEmpty()) {
            printf("\n Void Deletion. No elements in the list.");
        } else {
            hold = First;
            First=First->Next;
            free(hold);
            if (First == NULL) {
                Last = NULL;
            }
        }
    }
    ```
    2. #### Deletion at the end
    - To delete at the End of the Linked List.
    ```c
    void Delete_End() {
        Node *hold, *temp;
        if (isEmpty()) {
            printf("\n Void Deletion. No elements in the list.");
        } else if (First->Next==NULL) { // First Node is the Last Node
            free(First);
            First = NULL;
            Last = NULL;
            return;
        } else {
            DeleteEnd_logic();
        }
    }
    ```
    3. #### Deletion at a Position (INTUITIVE)
    - Delete anywhere in the List
    - Will Resolve in cases of Beginning and Ending detetion inferred throgh Posix
    ```c
    void Delete_Posix() {
        if(isEmpty()) {
            printf("\n Void Deletion. No elements in the list");
        } else {
            int Posix=getPosix();
            if ((Posix<=1)){
                Delete_Beginning();
            } else {
                Node *hold, *temp = First;
                for (int i=1; (i<Posix)&&(temp->Next->Next!=NULL);i++){
                    temp = temp -> Next;
                }
                if (temp-> Next->Next == NULL) {
                    Delete_End();
                } else {
                    hold = temp->Next;
                    temp -> Next = hold->Next;
                    free(hold);
                }
            }
        }
    }
    ```

3. ### **Node Count**:
    - To count the Number of Nodes in the Linked List.
    ```c
    int NodeCount() {
        Node *temp = First;
        int NodeCount=0;
        while (temp!=NULL) {
            NodeCount++;
            temp = temp->Next;
        }
        return NodeCount;
    }
    ```

4. ### **Display**:
    - To display the Nodes in the Linked List.
    ```c
    void  Display() {
        Node *temp = First;

        printf("[ ");
        while (temp!=NULL) {
            printf("%d,",temp->Item);
            temp = temp->Next;
        }
        printf("\b ]");
    }
    ```
5. ### **Search**:
    - To display the Nodes that contain the Element/Item.
    ```c
    void InitialPrint() {
        static int alreadycalled=0;
        if (!alreadycalled) {
            printf("Elements Found at Nodes: ");
            alreadycalled=1;
        } 
    }

    void Search() {
        Node *temp=First;
        if (isEmpty()) {
            printf("\n List is empty Cannot Search.");
        } else {
            int Item=getItem();
            for (int i=1;(temp!=NULL);i++) {
                if (temp->Item==Item) {
                    InitialPrint();
                    printf("%d,", i);
                }
                temp=temp->Next;
            }
            printf("\b  "); 
        }
    }
    ```