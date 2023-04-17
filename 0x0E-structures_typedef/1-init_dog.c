#include "dog.h"
#include <stddef.h>

/**
 * init_dog - Initializes a struct dog
 * @d: The struct dog to initialize
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner's name
 *
 * Description: This function initializes a struct dog with
 * the given name, age, and owner's name.
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
