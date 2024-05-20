# 🔄 Merge Sort
- The [CODE:📑](../../Data_Structures/Sorting_Algorithms.c#L128).
- The stable but not In-Place Sorting Algorithm.
- Sorts by Breaking the Array into smaller blocks until block with single elements and sorts them while merging it back.

## 🔢 Algorihm.
- The algorithm is as follows:
    1. Start
    2. Split the unsorted list into two groups recursively utnil there is one element per group.
    3. Compare each of the element and then sort and group them.
    4. Repeat step 2 and 3 until the whole list is merged and sorted.
    5. Stop

## 📝 Pseudo Code
- The Pseudo Code is as follows for ascending order. 
```
MergeSort(A, l, r) {
    if (l < r) {
        m = ⌊(l + r)/2⌋
        MergeSort(A, l, m);
        MergeSort(A, m+1, r);
        Merge(A, l, m+1, r)
    }
}

Merge(A, l, m, r) {
    x = l; 
    y = m;
    k = l;
    while (x < m && y <= Right) {
        if (A[x] < A[y]) {
            B[k++] = A[x++];
        }
        else {
            B[k++] = A[y++];
        }
    }
    while (x < Middle) {
        B[k++] = A[x++];
    }
    while (y <= Right) {
        B[k++] = A[y++];
    }

    for (int i=l; i<=r; i++) {
        A[i] = B[i];
    }
}
```

&nbsp;
# [Tracing](./MergeSortTracing.md)
- <img src="../Resources/MergeSort/MergeSortPass00Step00.svg" width=500px>
- Given an unsorted array like below, The sorting can be traced as: [Tracing:🧭](./MergeSortTracing.md).
