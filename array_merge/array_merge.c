#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    // Calculate the total number of elements in all arrays
    int total_size = 0;
    for (int i = 0; i < num_arrays; i++) {
        total_size += sizes[i];
    }

    // Allocate memory for the merged array
    int *merged_array = (int *)malloc(total_size * sizeof(int));
    if (merged_array == NULL) {
        return NULL; // Memory allocation failed
    }

    // Copy elements from all arrays into the merged array
    int current_index = 0;
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            merged_array[current_index++] = values[i][j];
        }
    }

    // Sort the merged array using mergesort
    mergesort(total_size, merged_array);

    return merged_array;
}
