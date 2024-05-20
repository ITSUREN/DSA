# ⚡ Quick Sort
- The [CODE:📑](../../Data_Structures/Sorting_Algorithms.c#L71).
- The In-Place but not Stable Sorting Algorithm.
- Sorts by partitioning the Array into a an array with elements lesser than the pivot and on with elements greater than the pivot.

## 🔢 Algorihm.
- The algorithm is as follows:
    1. Start
    2. Choose a Pivot.
    3. Compare the left pointer element (lelement) and right pointer element (relement) with Pivot.
    4. Check

    &nbsp;
    &emsp; i. If lelement <= Pivot increase the lelement;

    &nbsp;
    &emsp; ii. if relement >= Pivot decrease the relement;

    &nbsp;
    &emsp; iii. If not swap lelement and relelement

    7. When left >= right, swap the Pivot with either left or right pointer.
    8. Repeat steps 1-5 on the left half and the right half of hte list till the entire list is sorted.
    9. Stop

## 📝 Pseudo Code
- The Pseudo Code is as follows for ascending order. 
```
QuickSort(A, l, r) {
    if (l < r) {
        p = Partition(A, l, r);
        QuickSort(A, l, p-1);
        QuickSort(A, p+1, r);
    }
}

Partition(A, l, r) {
    x = l; 
    y = r;
    p = A[l];
    while (x < y) {
        while (A[x] <= p) {
            x++;
        }
        while (A[y] >= p) {
            y--;
        }
        if (x < y) {
            swap(A[x], A[y]);
        }
    }
    A[l] = A[y];
    A[y] = p;
    return y;
}
```

&nbsp;
# [Tracing](./QuickSortTracing.md)
- <img src="../Resources/QuickSort/QuickSortPass00Step00.svg" width=500px>
- Given an unsorted array like below, The sorting can be traced as: [Tracing:🧭](./QuickSortTracing.md).
