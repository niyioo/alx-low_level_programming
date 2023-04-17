#include "dog.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * free_dog - Frees dogs.
 * @d: Pointer to dog_t struct to free.
 *
 * Return: void
 */

void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
