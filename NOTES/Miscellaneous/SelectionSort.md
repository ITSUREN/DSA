# 🔍 Selection Sort
- The [CODE:📑](../../Data_Structures/Sorting_Algorithms.c#L54).
- The Simplest, In-Place and Stable Sorting Algorithm.
- Sorts by Finding the Smallest/Largest and swapping their places from Firt or Last Depending upon the order.

## 📝 Pseudo Code
- The Pseudo Code is as follows for ascending order. 
```
SelectionSort(A, n) {
    for i from 0 to n {
        Least = A[i];
        Index = i;
        for j from i+1 to n {
            if (A[j] < Least) {
                Least = A[j];
                Index = j;
            }
        }
        swap(A[i], A[Index]);
    }
}
```

&nbsp;
# [Tracing](./SelectionSortTracing.md)
- <img src="../Resources/SelectionSort/SelectionSortPass00Step00.svg" width=500px>
- Given an unsorted array like below, The sorting can be traced as: [Tracing:🧭](./SelectionSortTracing.md).
