#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // Include ctype.h for isdigit function

#define MAX 100 // For input Buffer

// Fundamental Blocks
int* allocator(int size, int type){ 
    int *ptr;
    switch (type)
    {
    case 1:
        ptr=(int*) malloc(size * sizeof(int)); //Using Malloc
        break;
    case 2:
        ptr=(int*) calloc(size, sizeof(int)); //Using Calloc
        break;
    default:
        printf("[Err 03]: (Internal) Unexpected Allocator type select parameter passed.");
        break;
    }
    if (ptr == NULL) {
        fprintf(stderr, "\n[ERR 01]: Memory Allocation Failed.\n");
        exit(EXIT_FAILURE);
    }
    printf("\n[RES]: Memory Allocated Successfully.\n");
    return ptr;
}

void reallocator(int **pointer, int size, int *state){
    int *temp = realloc(*pointer, size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "\n[ERR 05]: Memory Reallocation Failed.\n");
        exit(EXIT_FAILURE);
    }
    *pointer = temp;
    *state = 1;
}


int input(const char *prompt){
    int scan_var;
    char buffer[MAX]; // Buffer to store user input

    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin); // Read a line of input from the user

    // Convert the input to an integer
    if (sscanf(buffer, "%d", &scan_var) != 1) {
        printf("[ERR 02]: Please enter a valid integer.\n");
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
void result(int *pointer, int size, int type) {
    system("clear");
    printf("RESULTS:\n");
    printf("\nGiven Array: ");
    traverse(pointer, size);
    switch(type) {
        case 1:
            printf("\nSum of given Numbers is: %d\n", sum(pointer, size));
            break;
        case 2:
            printf("\nMultiplication of given Numbers is: %d\n", mult(pointer, size));
            break;
        default:
            printf("\n[ERR 04]: (Internal) Unexpected Selection operator on Result Function.\n");
    } 
}

int menu2_logic(int *pointer, int *size, int choice, int *state){
    switch (choice)
    {
    case 0:
        printf("\n Exiting Program.");
        exit(EXIT_SUCCESS);
    case 1:
        system("clear");
        *size = input("\nEnter the New Size: ");
        reallocator(&pointer, *size, state);
        break;
    case 2:
        result(pointer, *size, 1);
        break;
    case 3:
        result(pointer, *size, 2);
        break;
    default:
        printf("[ERRO P1]: Invalid Selection, try again");
        return 1;
        break;
    }
    return 0;
}

int menu(int stage) {
    system("clear");
    switch (stage)
    {
    case 0:
        printf("\n Exiting Program.");
        exit(EXIT_SUCCESS);
    case 1:
        return input("\nMENU: Memory Allocation\n\n1. malloc\n2. calloc\n\n=> "); 
    case 2:
        return input("\nMENU: Operations\n\n1. realloc\n2. sum\n3. multiply\n\n=> ");
    default:
        printf("[ERR 04]: (Internal) Unexpected menu selection parmeter passed.");
        break;
    }
} 

int main() {
    int *pointer, size, state=1;
    // Allocating Memory Blocks with malloc
    system("clear");
    size = input("Enter the size of integer array: ");
    pointer = allocator(size,menu(1));

    // Entering the elements
    do {
        if (state) {
            system("clear");
            fill(pointer, size);
        } else {
            getchar();
        }
        state = 0;
    } while (!menu2_logic(pointer, &size, menu(2), &state));

    // Free allocated memory
    free(pointer);
    return EXIT_SUCCESS;
}
