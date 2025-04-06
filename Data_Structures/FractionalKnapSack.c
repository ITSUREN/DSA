#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

int Values[]={30, 20, 100, 90, 160};
int Weights[MAXSIZE]={5, 10, 20, 30, 40};

void ListOutputFloat(int Size, float List[MAXSIZE]) {
    for (int i=0; i < Size; i++) {
        printf("\t%.2f", List[i]);
    }
    printf("\n");
}

void ListOutputInt(int Size, int List[MAXSIZE]) {
    for (int i=0; i < Size; i++) {
        printf("\t%d", List[i]);
    }
    printf("\n");
}

void Swap(int Index1, int Index2, float List[MAXSIZE]) {
    float Temporary = List[Index2];
    List[Index2] = List[Index1];
    List[Index1] = Temporary;
}

void Merge(float ListA[MAXSIZE], int Left, int Middle, int Right) {
    float tempProfits[MAXSIZE];
    int tempValues[MAXSIZE];
    int tempWeights[MAXSIZE];
    int x = Left, y = Middle;
    int k = Left;
    while (x < Middle && y <= Right) {
        if (ListA[x] > ListA[y]) {
            tempProfits[k] = ListA[x];
            tempValues[k] = Values[x];
            tempWeights[k] = Weights[x];
            x++;
        }
        else {
            tempProfits[k] = ListA[y];
            tempValues[k] = Values[y];
            tempWeights[k] = Weights[y];
            y++;
        }
        k++;
    }

    while (x < Middle) {
        tempProfits[k] = ListA[x];
        tempValues[k] = Values[x];
        tempWeights[k] = Weights[x];
        k++;
        x++;
    }
    while (y <= Right) {
        tempProfits[k] = ListA[y];
        tempValues[k] = Values[y];
        tempWeights[k] = Weights[y];
        k++;
        y++;
    }

    for (int i = Left; i <= Right; i++) {
        ListA[i] = tempProfits[i];
        Values[i] = tempValues[i];
        Weights[i] = tempWeights[i];
    }
}

void MergeSortInternal(float List[MAXSIZE], int Left, int Right) {
    if (Left < Right) {
        int Middle = (Left + Right) / 2;
        MergeSortInternal(List, Left, Middle);
        MergeSortInternal(List, Middle + 1, Right);
        Merge(List, Left, Middle + 1, Right);
    }
}

void MergeSort(int Size, float UnsortedList[MAXSIZE]) {
    MergeSortInternal(UnsortedList, 0, Size - 1);
}

void GreedyKnapSack(int Size, int Capacity,int Weights[MAXSIZE], float X[MAXSIZE]) {
    int i;
    for (i=0; i<Size; i++) {
        X[i] = 0.0;
    }
    int temporaryWeight=Capacity;
    for (i=0; i<Size;i++)  {
        if (Weights[i]>temporaryWeight) {
            break;
        }
        X[i]=1.0;
        temporaryWeight=temporaryWeight-Weights[i];
    }
    if (i<Size) {
        X[i]=(float)temporaryWeight/Weights[i];
    }
}

int main() {
    float Profits[MAXSIZE]={0.0};
    float X[MAXSIZE];
    int Capacity=60;
    int Size = sizeof(Values)/sizeof(Values[0]);

    for (int i=0; i<Size; i++) {
        Profits[i]=Values[i]/Weights[i];
    }

    system("clear");
    printf("UNSORTED:\nProfits: ");
    ListOutputFloat(Size, Profits);
    printf("Values: ");
    ListOutputInt(Size, Values);
    printf("Weights: ");
    ListOutputInt(Size, Weights);

    MergeSort(Size, Profits);
    printf("\nSORTED:\nProfits: ");
    ListOutputFloat(Size, Profits);
    printf("Values: ");
    ListOutputInt(Size, Values);
    printf("Weights: ");
    ListOutputInt(Size, Weights);

    GreedyKnapSack(Size, Capacity, Weights, X);
    printf("\nSOLUTION:\nX: ");
    ListOutputFloat(Size,X);
}