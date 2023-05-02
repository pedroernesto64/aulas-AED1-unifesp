// Pedro Ernesto Duarte Pilchowski - AED I - RA: 156.331
// Algorithm that receives the size of the array, generates random integers,
// inserts them into the array and sorts them using Insertion Sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
  
    for (i = 1; i < n; i++) { // Iterate over the array starting from the second element
        key = arr[i]; // Set the key to the current element
        j = i - 1; // Set j to the index of the previous element
        
        while (j >= 0 && arr[j] > key) { // While j is a valid index and the previous element is greater than the key
            arr[j + 1] = arr[j]; // Move the previous element to the current position
            j = j - 1; // Decrement j
        }
        
        arr[j + 1] = key; // Insert the key in the correct position
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
        arr[i] = rand() % n; // Generate random integers between 0 and n and add it to the array
        printf("%d ", arr[i]); // Print the integer to the console
    }
    clock_t t;
    t = clock(); // Get the current clock time
    insertionSort(arr, n); // Sort the array using the insertionSort function
    t = clock() - t; // Calculate the time taken to sort the array
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // Convert the clock ticks to seconds
    
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the sorted array
    }
    
    printf("\nTime taken: %f seconds\n", time_taken); // Print the time taken to sort the array to the console
    
    return 0;
}
