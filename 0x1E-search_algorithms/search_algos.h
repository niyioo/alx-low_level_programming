#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;

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

/* Function to perform jump search for singly linked list */
listint_t *jump_list(listint_t *list, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
