// Pedro Ernesto Duarte Pilchowski - AED I - RA: 156.331
// Algorithm that receives the size of the array, generates random integers,
// inserts them into the array and sorts them using Selection Sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    
  for (i = 0; i < n - 1; i++) { // Iterate over the array
        min_idx = i; // Set the minimum index to the current element
        for (j = i + 1; j < n; j++) { // Find the minimum element in the remaining array
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap the minimum element with the current element
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n]; // Create an array of size n
    srand(time(0)); // Seed the random number generator with the current time
    
    printf("Random integers: ");
    for (i = 0; i < n; i++) {
        arr[i] = rand() % n; // Generate a random integer between 0 and n and add it to the array
        printf("%d ", arr[i]); // Print the integer to the console
    }
    
    clock_t t;
    t = clock(); // Get the current clock time
    selectionSort(arr, n); // Sort the array using the selectionSort function
    t = clock() - t; // Calculate the time taken to sort the array
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // Convert the clock ticks to seconds
    
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the sorted array to the console
    }
    
    printf("\nTime taken: %f seconds\n", time_taken); // Print the time taken to sort the array to the console
    
    return 0;
}
