#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 50

// LIST OPERATIONS
void ListInput(int *Size, int UnsortedList[MAXSIZE]) {
    printf("Enter the number of elements: ");
    scanf("%d", Size);

    system("clear");
    printf("\nLIST INPUTS: \n\n Enter the elements of the list: ");
    for (int i=0; i < *Size; i++) {
        scanf("%d", &UnsortedList[i]);
    }
} 

void ListOutput(int Size, int List[MAXSIZE]) {
    printf("\n\tLIST OUTPUT: ");
    for (int i=0; i< Size; i++) {
        printf(" %d", List[i]);
    }
    printf("\n");
}

void ListCopy(int Size,int Source[MAXSIZE], int Destination[MAXSIZE]) {
    for (int i=0; i<Size; i++) {
        Destination[i]=Source[i];
    }
}

void Swap(int Index1, int Index2, int List[MAXSIZE]) {
    int Temporary = List[Index2];
    List[Index2] = List[Index1];
    List[Index1] = Temporary;
}

// SORTING ALGORITHMS
void BubbleSort(int Size, int UnsortedList[MAXSIZE]) {
    int SortedList[MAXSIZE];
    ListCopy(Size, UnsortedList, SortedList);

    for (int i=0; i < Size-1; i++) {
        for (int j=0; j < Size-i-1; j++) {
            if (SortedList[j] > SortedList[j+1]) {
                Swap(j, j+1, SortedList);
            }
        }
    }
    printf("\nBUBBLE SORT: ");
    ListOutput(Size, SortedList);
}

void SelectionSort(int Size, int UnsortedList[MAXSIZE]) {
    int SortedList[MAXSIZE], LeastIndex; 
    ListCopy(Size, UnsortedList, SortedList);

    for (int i=0; i < Size; i++) {
        LeastIndex=i;
        for (int j=i+1; j < Size; j++) {
            if (SortedList[j] <= SortedList[LeastIndex]) {
                LeastIndex=j;
            }
        }
        Swap(i, LeastIndex, SortedList);
    }
    printf("\nSELECTION SORT: ");
    ListOutput(Size, SortedList);
}

void InsertionSort(int Size, int UnsortedList[MAXSIZE]) {
    int SortedList[MAXSIZE], LeastIndex; 
    ListCopy(Size, UnsortedList, SortedList);

    for (int i=1; i < Size; i++) {
        int temp=SortedList[i];
        int j=i-1;
        while (j>=0 && SortedList[j] > temp) {
            SortedList[j+1] = SortedList[j];
            j=j-1;
        }
        SortedList[j+1] = temp;
    }
    printf("\nINSERTION SORT: ");
    ListOutput(Size, SortedList);
}

int QuickPartitioner(int List[MAXSIZE], int Left, int Right) {
    int pivot = List[Left];
    int smaller = Left;
    int equal = Left;
    int larger = Right;

    while (equal <= larger) {
        if (List[equal] < pivot) {
            Swap(smaller, equal, List);
            smaller++;
            equal++;
        } else if (List[equal] == pivot) {
            equal++;
        } else {
            Swap(equal, larger, List);
            larger--;
        }
    }

    return smaller;
}

void QuickSortInternal(int List[MAXSIZE], int Left, int Right) {
    if (Left < Right) {
        int p = QuickPartitioner(List, Left, Right);
        QuickSortInternal(List, Left, p - 1);
        QuickSortInternal(List, p + 1, Right);
    }
}

void QuickSort(int Size, int UnsortedList[MAXSIZE]) {
    int SortedList[MAXSIZE];
    ListCopy(Size, UnsortedList, SortedList);

    QuickSortInternal(SortedList, 0, Size - 1);

    printf("\nQUICK SORT: ");
    ListOutput(Size, SortedList);
}

int RandomizedQuickPartitioner(int List[MAXSIZE], int Left, int Right) {
    // Choose a random pivot and swap it with the left element
    int randomIndex = Left + rand() % (Right - Left + 1);
    Swap(Left, randomIndex, List);

    int pivot = List[Left];
    int i = Left + 1;
    for (int j = Left + 1; j <= Right; j++) {
        if (List[j] < pivot) {
            Swap(i, j, List);
            i++;
        }
    }
    Swap(Left, i - 1, List);
    return i - 1;
}

void RandomizedQuickSortInternal(int List[MAXSIZE], int Left, int Right) {
    if (Left < Right) {
        int p = RandomizedQuickPartitioner(List, Left, Right);
        RandomizedQuickSortInternal(List, Left, p - 1);
        RandomizedQuickSortInternal(List, p + 1, Right);
    }
}

void RandomizedQuickSort(int Size, int UnsortedList[MAXSIZE]) {
    srand(time(NULL)); // Seed random generator
    int SortedList[MAXSIZE];
    ListCopy(Size, UnsortedList, SortedList);
    RandomizedQuickSortInternal(SortedList, 0, Size - 1);

    printf("\nRANDOMIZED QUICK SORT: ");
    ListOutput(Size, SortedList);
}

void Merge(int ListA[MAXSIZE], int Left, int Middle, int Right) {
    int ListB[MAXSIZE];
    int x = Left, y = Middle;
    int k = Left;
    while (x < Middle && y <= Right) {
        if (ListA[x] < ListA[y]) {
            ListB[k++] = ListA[x++];
        }
        else {
            ListB[k++] = ListA[y++];
        }
    }

    while (x < Middle) {
        ListB[k++] = ListA[x++];
    }
    while (y <= Right) {
        ListB[k++] = ListA[y++];
    }

    for (int i = Left; i <= Right; i++) {
        ListA[i] = ListB[i];
    }
}

void MergeSortInternal(int List[MAXSIZE], int Left, int Right) {
    if (Left < Right) {
        int Middle = (Left + Right) / 2;
        MergeSortInternal(List, Left, Middle);
        MergeSortInternal(List, Middle + 1, Right);
        Merge(List, Left, Middle + 1, Right);
    }
}

void MergeSort(int Size, int UnsortedList[MAXSIZE]) {
    int SortedList[MAXSIZE];
    ListCopy(Size, UnsortedList, SortedList);

    MergeSortInternal(SortedList, 0, Size - 1);

    printf("\nMerge SORT: ");
    ListOutput(Size, SortedList);
}

void MaxHeapify(int List[MAXSIZE], int Index, int Size) {
    int Largest = Index;
    int Left = 2*Index + 1;
    int Right = 2*Index +2;
    if (Left < Size && List[Left] > List[Largest])
        Largest = Left;
    if (Right < Size && List[Right] > List[Largest]) 
        Largest = Right;
    
    if (Largest != Index) {
        Swap(Index, Largest, List);
        // Recursive Heapification
        MaxHeapify(List, Largest, Size);
    }
}

void HeapSort(int Size,int UnsortedList[MAXSIZE]) {
    int HeapArray[MAXSIZE];
    ListCopy(Size, UnsortedList, HeapArray);
    for (int i= (Size / 2)-1; i >=0; i--) 
        MaxHeapify(HeapArray, i, Size);
    
    for (int i= Size -1; i>=0; i--) {
        Swap(0, i, HeapArray);
        MaxHeapify(HeapArray, 0, i);
    }

    printf("\nHEAP SORT: ");
    ListOutput(Size, HeapArray);
}


int main() {
    int Size, UnsortedList[MAXSIZE];
    
    //system("clear");
    ListInput(&Size, UnsortedList);

    //system("clear");
    BubbleSort(Size, UnsortedList);
    SelectionSort(Size, UnsortedList);
    InsertionSort(Size, UnsortedList);
    QuickSort(Size, UnsortedList);
    MergeSort(Size, UnsortedList);
    HeapSort(Size, UnsortedList);
    RandomizedQuickSort(Size, UnsortedList);
}