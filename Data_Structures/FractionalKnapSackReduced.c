#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50

int Values[] = {30, 20, 100, 90, 160};
int Weights[] = {5, 10, 20, 30, 40};

// Structure to hold item data for sorting
typedef struct {
    float profit;
    int value;
    int weight;
} Item;

int compare(const void *a, const void *b) {
    float p1 = ((Item *)a)->profit;
    float p2 = ((Item *)b)->profit;
    return (p1 < p2) - (p1 > p2); // Descending order
}

void ListOutputFloat(int Size, float List[MAXSIZE]) {
    for (int i = 0; i < Size; i++) {
        printf("\t%.2f", List[i]);
    }
    printf("\n");
}

void ListOutputItems(int Size, Item items[]) {
    printf("Profits: ");
    for (int i = 0; i < Size; i++) {
        printf("\t%.2f", items[i].profit);
    }
    printf("\nValues:  ");
    for (int i = 0; i < Size; i++) {
        printf("\t%d", items[i].value);
    }
    printf("\nWeights: ");
    for (int i = 0; i < Size; i++) {
        printf("\t%d", items[i].weight);
    }
    printf("\n");
}

void GreedyKnapSack(int Size, int Capacity, Item items[], float X[MAXSIZE]) {
    for (int i = 0; i < Size; i++) {
        X[i] = 0.0;
    }
    int tempWeight = Capacity;
    int i;
    for (i = 0; i < Size; i++) {
        if (items[i].weight > tempWeight) {
            break;
        }
        X[i] = 1.0;
        tempWeight -= items[i].weight;
    }
    if (i < Size) {
        X[i] = (float)tempWeight / items[i].weight;
    }
}

int main() {
    int Size = sizeof(Values) / sizeof(Values[0]);
    Item items[MAXSIZE];
    float X[MAXSIZE];
    int Capacity = 60;

    for (int i = 0; i < Size; i++) {
        items[i].value = Values[i];
        items[i].weight = Weights[i];
        items[i].profit = (float)Values[i] / Weights[i];
    }

    system("clear");
    printf("UNSORTED:\n");
    ListOutputItems(Size, items);

    qsort(items, Size, sizeof(Item), compare);

    printf("\nSORTED:\n");
    ListOutputItems(Size, items);

    GreedyKnapSack(Size, Capacity, items, X);

    printf("\nSOLUTION:\nX: ");
    ListOutputFloat(Size, X);
    return 0;
}
