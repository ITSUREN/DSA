# 🔗 Singly Linked List
- The [CODE:📑](../Data_Structures/SinglyLinked_List.c).
- Has only One Structural pointer

### 🔧 Operations on a Priority Queue:
1. Inserting Elements
    - Inserting an Element at the Beginning
    - Inserting an Element at the End
    - Insserting an Element at a Specified position
2. Deleting Elements
    - Deleting an Element at the Beginning
    - Deleting an Element at the End
    - Deleting an Element at ts Specified Position
3. Counting number of Nodes
4. Displaying Nodes
5. Searching a Node
6. Merging Liked List

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
    - Will Resolve in cases of Front and End Insertion inferred throgh Posix
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

3. ### **Node Count**:
- To count the Number of Nodes in the Linked List.


4. ### **Display**:
    - To display the Nodes in the Linked List.
