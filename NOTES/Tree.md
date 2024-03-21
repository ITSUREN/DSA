# 🌲 Trees
- Non Linear Data Structure for modeling a hierarchical structure
- Single Parent, Multiple Children.


### 🔑 Key Characteristics of a Trees:
- **Nodes**: The elements that make up the tree
    1. **Root Node**: The First Node of the Tree.
    2. **Parent Node**: Nodes that have children/successors (except the Root Node).
    3. **Child Nodes**: Nodes that extend from another node.
    4. **Terminal/Leaf Node**: Nodes that have no children.

    - **Depth of a Node**: Length of the path from the root to that node.
    - **Height of a Node**: Legnth of the path from the node to the deepest leaf/terminal node.
- **Branches**: Directed Lines that show Parent-Child Relation and connect the nodes together.
- **Sub Tree**: Non Empty partition of Node other than Root .
- **Degree**: The number of Branches Associated with a node. 
    1. **In-Degree**: The number of Branches directed towards the node.
    2. **Out-Degree**: The number of Branches directed away from the node.
- **Levels**: The generation of nodes where root is 0 and increasing moving down.
- **Depth**: The length of  the largest path from root to the terminal nodes.
- **Keys**: Value of a node based on which the search is carried out.

### 🌿 Types of Trees
1. **[Binary Tree](./Binary_Tree.md)** : Trees with at most 2 child/successor Nodes.
2. **Ternary Tree**: Trees with at most 3 child/Successor Nodes.
3. **N-ary Tree**: Trees with at monst N child/Successor Nodes.

&nbsp;
# 🧰 Applications:
- **Hierarchical Modeling**:  Representing hierarchical data like file systems (folders and files), organizational charts (managers and employees), and biological classifications (species and genus).

- **Efficient Searching**: Binary search trees and other balanced trees allow fast searching by systematically narrowing down the search path.

- **Indexing**:  Used in databases to improve data retrieval speed by creating an organized index structure.

- **Machine Learning**: Decision trees are a machine learning technique used for classification and prediction based on a series of decisions.

- **Network Routing**: Routing protocols like DNS (Domain Name System) use tree structures to efficiently find the best path for data packets to travel across networks.

- **Syntax Parsing**: Parse trees help analyze the structure of code or text in programming languages and natural language processing.


