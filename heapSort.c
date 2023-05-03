// Pedro Ernesto Duarte Pilchowski - AED I - RA: 156.331
// Algorithm that receives the size of the array, generates random integers,
// inserts them into the array and sorts them using Insertion Sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    
    // Check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    
    // Swap root with largest element if needed
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        
        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    // Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        
        // Recursively heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    // Allocate memory for the array
    int *arr = malloc(n * sizeof(int));
    
    // Generate random array
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n; // Random integers between 0 and n
    }
    
    // Print unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Sort array using Heap Sort and measure time
    clock_t start = clock();
    heapSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    // Print sorted array and time taken
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nTime taken: %f seconds\n", time_taken);
    
    // Free memory and return
    free(arr);
    return 0;
}
