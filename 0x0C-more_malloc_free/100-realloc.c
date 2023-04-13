#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 *
 * @ptr: Pointer to the previously allocated memory block
 * @old_size: The size, in bytes, of the allocated space for ptr
 * @new_size: The new size, in bytes, of the new memory block
 *
 * Return: Pointer to the reallocated memory block
 * NULL if new_size is zero and ptr is not NULL
 * NULL if malloc fails or if min is greater than max
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;

	void *new_ptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size > old_size)
		new_size = old_size;

	for (i = 0; i < new_size; i++)
		*((char *)new_ptr + i) = *((char *)ptr + i);

	free(ptr);

	return (new_ptr);
}
