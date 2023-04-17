#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a dog's attributes
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner's name
 *
 * Description: This structure defines a dog's attributes
 * including its name, age, and owner's name.
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(dog_t *d, char *name, float age, char *owner);
void print_dog(dog_t *d);

#endif /* DOG_H */
