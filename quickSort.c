// Pedro Ernesto Duarte Pilchowski - AED I - RA: 156.331
// Algorithm that receives the n of the array, generates random integers,
// inserts them into the array and sorts them using Quick Sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int arr[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2]; // Choose pivot element as middle element
    
    // Partition the subarray
    while (i <= j) {
        while (arr[i] < pivot) { // Find first element on left that is >= pivot
            i++;
        }
        while (arr[j] > pivot) { // Find first element on right that is <= pivot
            j--;
        }
        if (i <= j) { // Swap elements if they are out of place
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
    // Recursively call quickSort on left and right subarrays
    if (left < j) { // Sort left subarray if it has more than one element
        quickSort(arr, left, j);
    }
    if (i < right) { // Sort right subarray if it has more than one element
        quickSort(arr, i, right);
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
    
    // Sort array using Quick Sort and measure time
    clock_t start = clock();
    quickSort(arr, 0, n - 1);
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
