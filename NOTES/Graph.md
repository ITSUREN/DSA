# 📉 Graphs
- A non Linear Data Structure containing Vertices(Nodes) and Edges(Links).
- An ordered par of SEt of Vertices and edges i.e $ G = (V, E) $.

### 🌿 Types of Graphs:
1. #### **Undirected Graph**:
- A graph with E where the order of inital vertex and final vertex does not matter.
  1. ##### **Simple Graph**:
  - A graph in which if a function **f** is assumed to be from E to {(u,v) | u,v ∈ V} where f(e1) ≠ f(e2) and u ≠ v.
  - That is a graph with no loops and no multiple edges.
  2. ##### **Multi Graph**:
  - A graph in which if a function **f** is assumed to be from E to {(u,v) | u,v ∈ V} where f(e1) = f(e2) and u ≠ v.
  - That is a graph with no loops but with multiple edges.
  3. #### **Pseudo Graph**:
  - A graph in which if a function **f** is assumed to be from E to {(u,v) | u,v ∈ V} where f(e1) = f(e2) and u = v.
  - That is a graph with both loops and multiple edges.
2. #### **Directed Graph**:
- A graph wih E where the order of inital vertex and final vertex matters.
- Has the same classification as Undirected Graphs.
3. ### **Mixed Graph**:
- A graph with both Directed and Undirected Edges and thus the properties.

### 🌐 Representation of Graphs.
1. #### **Adjacency List**:
- Specifies the vertices that are adjacent to each vertex.
- Suitable for graphs without multiple edges, and directed graphs.
2. #### **Adjacency Matrix**:
- Uses a Square Matrix with the size as the number of vertices to store edges.
- <img src="https://latex.codecogs.com/svg.image?\inline&space;{\color{Cyan}a_{ij}=\begin{cases}1&\text{if&space;}(v_i,v_j)\text{is&space;an&space;edge&space;in&space;}G,\\0&\text{otherwise.}\end{cases}}">
3. ### **Incidence Matrix**:
- Uses the Rectangular Matrix correspoding to Number of Edges and number of vertices.
- <img src="https://latex.codecogs.com/svg.image?\inline&space;{\color{Cyan}m_{ij}=\begin{cases}1&\text{when&space;edge&space;}e_j\text{is&space;incident&space;with&space;}v_i,\\0&\text{otherwise.}\end{cases}}">


&nbsp;
## 🚶‍♂️Graph Traversals
- The methods of exploring the vertices in graph
1. ### **[Breadh First Searh Traversal (BFS) 🚧](./BFS.md)**
2. ### **[Depth First Search Traversal (DFS) 🚧](./DFS.md)**

&nbsp;
## 🚀 Shortest Path Algorithms
- To find the Shortest Path between two vertices.
- Types of problems 
    1. Single Source shortest path problem.
    - To find shortest paths from a single source vertex to all other vertices.
    2. Single Destination shortest path problem.
    - To find shortest paths to a single destination vertext form all other vertices.
    3. Single Pair shortest path problem.
    - To find shortest path from a  singel source vertext to a single destination vertex.
    4. All Pair.
    - To find shortest paths from every vertex to every other vertex.
- Algorithms.
1. ### **[Dijkstra's Algorithm](./Dijkstras.md)**
2. ### **[A\* Algorithm 🚧](./Astar.md)**

## 🌲 Mimimum Spanning Trees.
- To find a connected weighted graph with least possible total weights of its edges out of all spanning trees.
1. ### **[Kruskal's Algorithm 🚧](./KruskalMST.md)**
2. ### **[Prim's Algorithm 🚧](./PrimsMST.md)**