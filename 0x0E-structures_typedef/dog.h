#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a dog's attributes
 *
 * @name: The dog's name
 * @age: The dog's age
 * @owner: The dog's owner's name
 *
 * Description: This structure defines a dog's attributes
 * including its name, age, and owner's name.
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);

#endif
