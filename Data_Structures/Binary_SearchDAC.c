#include <stdio.h>
#include "./modules/c_functions_linux.c"

int binary_search_recursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] < target) {
        return binary_search_recursive(arr, mid + 1, high, target);
    } else {
        return binary_search_recursive(arr, low, mid - 1, target);
    }
}

int main() {
    system("clear");
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 12;
    int result = binary_search_recursive(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
}
