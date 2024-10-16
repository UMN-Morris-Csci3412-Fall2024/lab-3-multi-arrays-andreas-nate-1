#include <stdlib.h>
#include <stdio.h>
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
    // Debug: Print input parameters
    printf("num_arrays: %d\n", num_arrays);
    if (sizes == NULL) {
        fprintf(stderr, "Error: sizes is NULL\n");
        return NULL;
    }
    if (values == NULL) {
        fprintf(stderr, "Error: values is NULL\n");
        return NULL;
    }

    // Calculate the total number of elements in all arrays
    int total_size = 0;
    for (int i = 0; i < num_arrays; i++) {
        if (sizes[i] < 0) {
            fprintf(stderr, "Error: sizes[%d] is negative\n", i);
            return NULL;
        }
        total_size += sizes[i];
    }

    // Handle the case where there are no elements in any of the arrays
    if (total_size == 0) {
        printf("Total size is 0, returning NULL\n");
        return NULL;
    }

    // Allocate memory for the merged array
    int *merged_array = (int *)malloc(total_size * sizeof(int));
    if (merged_array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL; // Memory allocation failed
    }

    // Copy elements from all arrays into the merged array
    int current_index = 0;
    for (int i = 0; i < num_arrays; i++) {
        if (values[i] == NULL) {
            fprintf(stderr, "Error: values[%d] is NULL\n", i);
            free(merged_array);
            return NULL;
        }
        for (int j = 0; j < sizes[i]; j++) {
            merged_array[current_index++] = values[i][j];
        }
    }

    // Sort the merged array using mergesort
    mergesort(total_size, merged_array);

    return merged_array;
}
