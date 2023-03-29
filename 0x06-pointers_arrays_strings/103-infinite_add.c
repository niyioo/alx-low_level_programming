#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result or 0 if the result can't be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, sum, carry;

	i = j = carry = 0;
	while (n1[i] != '\0')
		i++;
	while (n2[j] != '\0')
		j++;
	k = i > j ? i : j;
	if (k >= size_r)
		return (0);
	r[k] = '\0';
	for (i--, j--, l = k - 1; l >= 0; i--, j--, l--)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		carry = sum / 10;
		r[l] = (sum % 10) + '0';
	}
	if (carry && k + 1 <= size_r)
	{
		for (l = k; l >= 0; l--)
			r[l + 1] = r[l];
		r[0] = carry + '0';
		return (r);
	}
	else if (carry)
		return (0);
	return (r);
}
