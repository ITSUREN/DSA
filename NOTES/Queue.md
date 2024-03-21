# 🔁 Queue
- The [CODE:📑](../Data_Structures/Queue.c).
- A special type of [List](./List.md) or [Linked List](./Linked_List.md)
- linear data structure that follows 
- First-In-First-Out (FIFO) principle

### 🔑 Key Characteristics of a Queue:
- **FIFO** (First-In-First-Out): The element that is inserted first will be the first one to be removed.
- **Two Operations**: Queues typically support two primary operations:
    1. **Enqueue**: Adding an element to the end of the queue.
    2. **Dequeue**: Removing an element from the front of the queue.
- **No Random Access**: Unlike arrays, queues do not support random access to elements. You can only access the front and rear elements.
- **Sequential Storage**: Elements are stored sequentially, with each element connected to its adjacent ones.

### 🔧 Operations on a Queue:
1. **Enqueue**: Adds an element to the rear of the queue.
2. **Dequeue**: Removes and returns the element from the front of the queue.
3. **Peek** (or Front): Returns the element at the front of the queue without removing it.
4. **isEmpty**: Checks if the queue is empty.
5. **isFull**: Checks if the queue is full (applicable for fixed-size queues).

### 🌿 Types of Queues:
1. #### **[Linear Queue](./Linear_Queue.md)**: 
- The simplest form of a queue where elements are arranged in a linear manner. It has a fixed size and follows the FIFO principle.
2. #### **[Circular Queue](./Circular_Queue.md)** (Circular Buffer): 
- A variation of the linear queue where the rear and front pointers wrap around the array when they reach the end, making efficient use of space.
3. #### **[Priority Queue](./Priority_Queue.md)**: 
- A queue where elements have a priority associated with them, and elements with higher priority are dequeued first.

## 🧰 Applications of Queues:
1. **Job Scheduling**: Queues are used in operating systems for task scheduling, managing jobs to be executed.
2. **Breadth-First Search** (BFS): Queues are used to traverse graphs in a breadth-first manner.
3. **Printer Spooling**: Queues are used to manage print jobs, ensuring they are printed in the order they were received.
4. **Resource Sharing**: Queues can be used to manage access to shared resources, ensuring fair access to all users.
5. **Buffering**: Queues are used in computer networking for buffering data packets, ensuring smooth transmission.