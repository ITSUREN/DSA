#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

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

// SELECTION PROBLEM (FINDING KTH SMALLEST ELEMENT)
int RandomizedSelectionPartition(int List[MAXSIZE], int Left, int Right) {
    int randomIndex = Left + rand() % (Right - Left + 1);
    Swap(randomIndex, Right, List);  // Move random pivot to end
    int pivot = List[Right];
    int i = Left;
    for (int j = Left; j < Right; j++) {
        if (List[j] <= pivot) {
            Swap(i, j, List);
            i++;
        }
    }
    Swap(i, Right, List);
    return i;
}

int SelectionProblem(int List[MAXSIZE], int Left, int Right, int k) {
    if (Left <= Right) {
        int pos = RandomizedSelectionPartition(List, Left, Right);
        if (pos == k) {
            return List[pos];
        } else if (pos > k) {
            return SelectionProblem(List, Left, pos - 1, k);
        } else {
            return SelectionProblem(List, pos + 1, Right, k);
        }
    }
    return -1;
}

void SolveSelectionProblem(int Size, int UnsortedList[MAXSIZE], int k) {
    int CopyList[MAXSIZE];
    ListCopy(Size, UnsortedList, CopyList);
    int result = SelectionProblem(CopyList, 0, Size - 1, k - 1);
    
    if (result != -1) {
        printf("\nThe %d-th smallest element is: %d\n", k, result);
    } else {
        printf("\nInvalid k value!\n");
    }
}

int main() {
    int UnsortedList[] = {12, 45, 67, 89, 34, 56, 78};
    int Size = sizeof(UnsortedList) / sizeof(UnsortedList[0]);
    int k = 3; 
    
    system("clear");
    printf("INITIAL ARRAY: ");
    ListOutput(Size, UnsortedList);

    SolveSelectionProblem(Size, UnsortedList, k);
}
