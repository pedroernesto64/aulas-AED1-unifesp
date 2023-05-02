// Pedro Ernesto Duarte Pilchowski - AED I - RA: 156.331
// Algorithm that receives the size of the array, generates random integers,
// inserts them into the array and sorts them using Merge Sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    // Declare variables for indices and sizes of subarrays
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    
    // Declare arrays to hold subarrays
    int L[n1], R[n2];
    
    // Copy data into subarrays
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i]; // Copy first half of arr into L
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j]; // Copy second half of arr into R
    }
    
    // Merge the subarrays back into arr
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // If element in L is smaller or equal, copy it into arr
            i++; // Move to the next element in L
        }
        else {
            arr[k] = R[j]; // If element in R is smaller, copy it into arr
            j++; // Move to the next element in R
        }
        k++; // Move to the next element in arr
    }
    
    // Copy any remaining elements from L and R back into arr
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Executes the Merge Sort recursive operation
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, n - 1); // Sort the array using the mergeSort function
    t = clock() - t; // Calculate the time taken to sort the array
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // convert the clock ticks to seconds
    
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print the sorted array to the console
    }
    
    printf("\nTime taken: %f seconds\n", time_taken); // Print the time taken to sort the array to the console
    
    return 0;
}
