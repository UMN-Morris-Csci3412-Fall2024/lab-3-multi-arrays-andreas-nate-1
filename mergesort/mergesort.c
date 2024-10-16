#include "mergesort.h"
#include <stdlib.h>

void mergesort(int size, int values[]) {
    if (size <= 1) {
        return; // Base case: already sorted
    }

    int mid = size / 2;

    // Allocate memory for temporary arrays
    int *left = (int *)malloc(mid * sizeof(int));
    int *right = (int *)malloc((size - mid) * sizeof(int));

    // Populate temporary arrays
    for (int i = 0; i < mid; i++) {
        left[i] = values[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = values[i];
    }

    // Recursively sort subarrays
    mergesort(mid, left);
    mergesort(size - mid, right);

    // Merge sorted subarrays
    int i = 0, j = 0, k = 0;
    while (i < mid && j < size - mid) {
        if (left[i] <= right[j]) {
            values[k++] = left[i++];
        } else {
            values[k++] = right[j++];
        }
    }

    // Copy remaining elements (if any)
    while (i < mid) {
        values[k++] = left[i++];
    }
    while (j < size - mid) {
        values[k++] = right[j++];
    }

    // Free dynamically allocated memory
    free(left);
    free(right);
}
