# ➕ Insertion Sort
- The [CODE:📑](../../Data_Structures/Sorting_Algorithms.c#L88).
- The In-Place and Stable Sorting Algorithm.
- Sorts by Finding an element's position in the previously sorted group of prior elements and places it.

## 📝 Pseudo Code
- The Pseudo Code is as follows for ascending order. 
```
InsertionSort(A, n) {
    for i from 1 to n {
        Temp = A[i];
        j=i-1;
        while (j>=0 && Temp > A[j]) {
            A[j+1] = A[j]; //Clears an empty place
            j--;
        }
        A[j+1] = Temp;
    }
}
```

&nbsp;
# [Tracing 🚧](./InsertionSortTracing.md)
- <img src="../Resources/InsertionSort/InsertionSortPass00Step00.svg" width=500px>
- Given an unsorted array like below, The sorting can be traced as: [Tracing:🧭 🚧](./InsertionSortTracing.md).
