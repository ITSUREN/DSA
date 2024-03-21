# 🌳 Binary Search Tree
- The [CODE:📑](../Data_Structures/Binary_Search_Tree.c).
- A tree of finite set of elements that can be paritioned into 3 Disjoint subsets
- 3 Disjoint Subjset: Root, Left Sub-trees, and Right Sub-trees.
- The left of the parent node must always be smaller than the Parent and the Right should conversely be the greater value.

### 🔧 Operations on a Binary Search Tree:
1. **[Insertion](#insertion)**: Adding a new node to the binary search tree.
2. **Deletion**(🚧 TODO): Removing a node from the binary search tree. (Will do after I do AVL tree, complicated right now)
3. **[Traversal](#traverse)**:
- Display the tree:
    1. **[In-order Traversal](#inorder-traversal)**: Visit nodes in the order (left, root, right).
    2. **[Pre-order Traversal](#preorder-traversal)**: Visit nodes in the order (root, left, right).
    3. **[Post-order Traversal](#postorder-traversal)**: Visit nodes in the order (left, right, root).
4. **[Search](#search)**: Finding a specific element in the binary search tree.

&nbsp;
# 🧩 **Operations**
### ✔️ Checks Used
2. #### **isEmpty** check: 
    - Checking if Node is empty.
    ```c
    int isEmpty(Node *Root) {
        return (Root==NULL);
    }
    ```

### 🛠️ Methods Used
2. #### **Insertion**:
- To add elements to the Tree.
    ```c
    void Insert_Logic(Node **NewNode,int Key) {
        (*NewNode)->Key=Key;
        (*NewNode)->Left=NULL;
        (*NewNode)->Right=NULL;
    }

    Node *Insert(Node *ParentNode, int Key) {
        if (isEmpty(Root)) {
            Node *NewNode=(Node *)malloc(sizeof(Node));
            Insert_Logic(&NewNode, Key);
            Root=NewNode;
        } else if (Key<ParentNode->Key) {
            if(ParentNode->Left==NULL) {
                Node *NewNode = (Node *)malloc(sizeof(Node));
                Insert_Logic(&NewNode, Key);
                ParentNode->Left=NewNode;
            } else {
                Insert(ParentNode->Left, Key);
            }
        } else {
            if (ParentNode->Right==NULL) {
                Node *NewNode = (Node *)malloc(sizeof(Node));
                Insert_Logic(&NewNode, Key);
                ParentNode->Right=NewNode;
            } else {
                Insert(ParentNode->Right, Key);
            }
        }
    }

    void Insert_Interface() {
        int Key=getKey();
        Insert(Root, Key);
    }
    ```

3. #### **Traverse**:
    - To display Elements in a certain Manner.
    1. ##### Preorder Traversal
    ```c
    void InitialPrint() {
        if (!alreadycalled) {
            printf("Items Are: ");
            alreadycalled=1;
        } 
    }

    void PreorderTraversal(Node *ParentNode){
        InitialPrint();
        if (isEmpty(Root)) {
            printf("\n Tree Empty.");
        } else if (!isEmpty(ParentNode)){
            printf("%d, ",ParentNode->Key);
            PreorderTraversal(ParentNode->Left);
            PreorderTraversal(ParentNode->Right);
        }
    }
    ```
    2. ##### Inorder Traversal
    ```c
    void InorderTraversal(Node *ParentNode){
        InitialPrint();
        if (isEmpty(Root)) {
            printf("\n Tree Empty.");
        } else if (!isEmpty(ParentNode)){
            InorderTraversal(ParentNode->Left);
            printf("%d, ",ParentNode->Key);
            InorderTraversal(ParentNode->Right);
        }
    }
    ```
    3. ##### Postorder Traversal
    ```c
    void PostorderTraversal(Node *ParentNode){
        InitialPrint();
        if (isEmpty(Root)) {
            printf("\n Tree Empty.");
        } else if (!isEmpty(ParentNode)){
            PostorderTraversal(ParentNode->Left);
            PostorderTraversal(ParentNode->Right);
            printf("%d, ",ParentNode->Key);
        }
    }
    ```

5.  #### **Search** 
    - To Search an item
    ```c
    Node *Search(Node *ParentNode, int Key) { 
        if (isEmpty(Root)) {
            return NULL;
        } else if (Key==ParentNode->Key) {
        return ParentNode;
        } else if(Key<ParentNode->Key) {
            return Search(ParentNode->Left, Key);
        } else {
            return Search(ParentNode->Right, Key);
        }
    }

    void SearchInterface() {
        int Key =getKey();
        Node *temp=Search(Root,Key);
        if (temp==NULL) {
            printf("\nCouldn't Find the Element in the Tree");
        } else {
            printf("\nElement Found with Parent Node %d and %d siblings",ParentNodeFind(Root,temp)->Key, numberofSiblings(temp));
        }
    }
    ```


