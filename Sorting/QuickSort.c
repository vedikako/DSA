#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Choose the pivot as the first element
    int i = low;
    int j = high;

    do {
        // Move `i` to the right until an element greater than the pivot is found
        do {
            i++;
        } while (arr[i] <= pivot && i <= high);

        // Move `j` to the left until an element less than the pivot is found
        do {
            j--;
        } while (arr[j] > pivot);

        // If `i` is still to the left of `j`, swap elements at `i` and `j`
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    // Place the pivot element in its correct position
    swap(&arr[low], &arr[j]);
    return j;  // Return the pivot index
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);  // Get the pivot index

        // Recursively sort the left and right subarrays
        quickSort(arr, low, pivotIndex);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n);  // Sort the array

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
