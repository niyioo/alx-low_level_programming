#include "main.h"

/**
 * _memcpy - Copies n bytes from memory area src to memory area dest
 *
 * @dest: Pointer to the memory area to copy to
 * @src: Pointer to the memory area to copy from
 * @n: The number of bytes to copy
 *
 * Return: A pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}

	return (dest);
}
