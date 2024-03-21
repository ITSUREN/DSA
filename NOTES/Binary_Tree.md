# 🌳 Binary Tree
- A tree of finite set of elements that can be paritioned into 3 Disjoint subsets
- 3 Disjoin Subjest: Root, Left Sub-trees, and Right Sub-trees.

### 🌿 Types of Binary Trees:
1. **Binary Search Trees**:
    - Elements in the Left Subtree are less than or equal to Parent Node's value and 
    - Element in the Right Subtree are greater than Parent Node's value.
1. **Stricty Binary Trees**:
    - Evey non-leaf node has noneempty left and right subtrees.
    - Degrees of every node is either zero or two but never 1.
2. **Full Binary Tree**:
    - Strictly Binary Tree
    - A binary tree of height h with no missing node
    - if:
        1. **i** is number of internal nodes, 
        2. **l** is number of leaves,
        3. **n** is number of nodes
    ```py
        l=i+1
        n=2*i+1
    ```
3. **Complete Binary Tree**:
    - Non Strict Binary Tree
    - All levels of tree are filled except the lowest level, which are filled from as left as possible.
    - This is done such that that when traversing there is not NULL element.
4. **Perfect Binary Tree**:
    - Full + Complete Binary tree:
5. **Degenerate Binary Tree**:
    - Each Node has only one child
6. **Balanced Binary Tree**: 
    - height difference between the left and right subtrees of any node is not greater than one.

### 🔑 Key Characteristics of Binary Tree:
- **Maximum number of Child Nodes**: 2.
- **Duplicate Values**: NO
- **Maximum Number of Nodes**: 
    1. If L is the level of the tree:
    ```py
    NumberofNodes = 2^(L-1)
    ```
    2. If H is the Height of the tree:
    ```py
    NumberofNodes = 2^(L)-1
    ```
- **Maximum Level**:
    - If l is the number of leaves
    ```py
    level = Log2(l)+1
    ```

### 🔧 Operations on a Queue:
1. **Insertion**: Adding a new node to the binary tree.
2. **Deletion**: Removing a node from the binary tree.
3. **Traversal**:
- Display the tree:
    1. **In-order Traversal**: Visit nodes in the order (left, root, right).
    2. **Pre-order Traversal**: Visit nodes in the order (root, left, right).
    3. **Post-order Traversal**: Visit nodes in the order (left, right, root).
4. **Search**: Finding a specific element in the binary tree.


