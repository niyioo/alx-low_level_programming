#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

/* Function to perform linear search */
int linear_search(int *array, size_t size, int value);

/* Function to perform binary search */
int binary_search(int *array, size_t size, int value);

/* Function to perform Jump search */
int jump_search(int *array, size_t size, int value);

/* Function to perform Interpolation search */
int interpolation_search(int *array, size_t size, int value);

/* Function to perform Exponential search */
int exponential_search(int *array, size_t size, int value);

/* Function to perform advanced binary search */
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
