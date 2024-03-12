#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Include ctype.h for isdigit function

#define MAX 100 // For input Buffer

// Fundamental Blocks
int* allocator(int size){ 
    int *ptr = (int*)malloc(size * sizeof(int)); // Allocate memory for an array of 'size' integers
    if (ptr == NULL) {
        fprintf(stderr, "\n[ERR 01]: Memory Allocation Failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("\n[RES]: Memory Allocated Successfully.\n");
    return ptr;
}

int input(const char *prompt){
    int scan_var;
    char buffer[MAX]; // Buffer to store user input

    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin); // Read a line of input from the user

    // Convert the input to an integer
    if (sscanf(buffer, "%d", &scan_var) != 1) {
        printf("[Err 02]: Please enter a valid integer.\n");
        exit(EXIT_FAILURE);
    }
    return scan_var;
}

void fill(int *pointer, int size){
    printf("Enter %d elements: \n", size);
    for (int i = 0; i < size; i++){
        pointer[i] = input("");
    }     
}

int sum(int *pointer, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++){
        sum = sum + pointer[i];
    }
    return sum;
}

int mult(int *pointer, int size) {
    int mult = 1;
    for (int i = 0; i < size; i++){
        mult = mult * pointer[i];
    }
    return mult;
}

void traverse(int *pointer, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d,", pointer[i]);
    }
    printf("\b]");
}

// Composite Blocks
void result(int *pointer, int size) {
    printf("RESULTS:\n");
    printf("\nGiven Array: ");
    traverse(pointer, size);
    printf("\nSum of given Numbers is: %d", sum(pointer, size));
    printf("\nMultiplication of given Numbers is: %d\n", mult(pointer, size));
}

int main() {
    int *pointer, size;
    // Allocating Memory Blocks with malloc
    system("clear");
    size = input("Enter the size of integer array: ");
    pointer = allocator(size);

    // Entering the elements
    system("clear");
    fill(pointer, size);

    // Outputting the results
    system("clear");
    result(pointer, size);

    // Free allocated memory
    free(pointer);
    return EXIT_SUCCESS;
}
