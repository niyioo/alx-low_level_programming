#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number
 * @n2: Second number
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result, or 0 if the result cannot be stored
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, len1 = 0, len2 = 0, sum, carry = 0;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 + 2 > size_r || len2 + 2 > size_r)
		return (0);
	r[size_r - 1] = '\0';
	for (i = len1 - 1, j = len2 - 1, k = size_r - 2; i >= 0 || j >= 0; i--, j--, k--)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		if (k < 0)
			return (0);
		carry = sum / 10;
		r[k] = (sum % 10) + '0';
	}
	if (carry == 1)
	{
		if (k < 0)
			return (0);
		r[k] = '1';
		return (r + k);
	}
	return (r + k + 1);
}
