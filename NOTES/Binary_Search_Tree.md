# 🌳 Binary Search Tree
- The [CODE:📑](../Data_Structures/Binary_Search_Tree.c).
- A tree of finite set of elements that can be partitioned into 3 Disjoint subsets.
- 3 Disjoint Subjset: Root, Left Sub-trees, and Right Sub-trees.
- The left of the parent node must always be smaller than the Parent and the Right should conversely be the greater value.

### 🔧 Operations on a Binary Search Tree:
1. **[Insertion](#insertion)**: Adding a new node to the binary search tree.
2. **[Deletion](#delete)**: Removing a node from the binary search tree.
3. **[Traversal](#traverse)**:
- Display the tree:
    1. **[In-order Traversal](#inorder-traversal)**: Visit nodes in the order (left, root, right).
    2. **[Pre-order Traversal](#preorder-traversal)**: Visit nodes in the order (root, left, right).
    3. **[Post-order Traversal](#postorder-traversal)**: Visit nodes in the order (left, right, root).
4. **[Search](#search)**: Finding a specific element in the binary search tree.

&nbsp;
# 🧩 **Operations**
### ✔️ Modules Used
1. #### **isEmpty** check: 
    - Checking if Node is empty.
    ```c
    int isEmpty(Node *Root) {
        return (Root==NULL);
    }
    ```
2. #### **Find Min**:
    - Find's the lefmost element.
    ```c
    Node* FindMin(Node* node) {
        if (node == NULL)
            return NULL;

        while (node->Left != NULL)
            node = node->Left;

        return node;
    }
    ```

### 🛠️ Methods Used
1. #### **Insertion**:
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

2. #### **Delete**:
- To delete elements from the Tree.
    ```c
    Node* Delete(Node *root, int key) {
        if (root == NULL) {
            printf("\n Tree Empty. Nothing to Delete.");
            return root;
        }

        if (key < root->Key) {
            root->Left = Delete(root->Left, key);
        } else if (key > root->Key) {
            root->Right = Delete(root->Right, key);
        } else {
            // Node with only one child or no child
            if (root->Left == NULL) {
                Node *temp = root->Right;
                free(root);
                return temp;
            } else if (root->Right == NULL) {
                Node *temp = root->Left;
                free(root);
                return temp;
            }

            else {
                // Node with two children: Get the inorder successor (smallest in the right subtree)
                Node* temp = FindMin(root->Right);
                // Copy the inorder successor's content to this node
                root->Key = temp->Key;
                // Delete the inorder successor
                root->Right = Delete(root->Right, temp->Key);
            }
        }
        return root; //no need 
    }

    void Delete_Interface() {
        int Key=getKey();
        Delete(Root,Key);
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
    - To Search an item.
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


