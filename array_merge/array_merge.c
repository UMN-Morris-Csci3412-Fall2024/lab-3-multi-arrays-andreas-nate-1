#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>
#include <stdbool.h>

int* array_merge(int num_arrays, int* sizes, int** values) {
    // Calculate the total number of elements
    int total_elements = 0;
    for (int i = 0; i < num_arrays; i++) {
        total_elements += sizes[i];
    }

    // Allocate memory for a temporary array to hold all elements
    int* temp_array = (int*)malloc(total_elements * sizeof(int));
    int temp_index = 0;

    // Copy all elements into the temporary array
    for (int i = 0; i < num_arrays; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            temp_array[temp_index++] = values[i][j];
        }
    }

    // Sort the temporary array
    mergesort(total_elements, temp_array);

    // Count unique elements
    int unique_count = 0;
    if (total_elements > 0) {
        unique_count = 1; // First element is always unique
        for (int i = 1; i < total_elements; i++) {
            if (temp_array[i] != temp_array[i - 1]) {
                unique_count++;
            }
        }
    }

    // Allocate memory for the result array
    int* result = (int*)malloc((unique_count + 1) * sizeof(int));
    result[0] = unique_count;

    // Copy unique elements into the result array
    int result_index = 1;
    if (total_elements > 0) {
        result[result_index++] = temp_array[0];
        for (int i = 1; i < total_elements; i++) {
            if (temp_array[i] != temp_array[i - 1]) {
                result[result_index++] = temp_array[i];
            }
        }
    }

    // Free the temporary array
    free(temp_array);

    return result;
}
