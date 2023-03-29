#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number as a string
 * @n2: second number as a string
 * @r: buffer to store the result
 * @size_r: size of the buffer
 *
 * Return: pointer to the result, or 0 if the result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, l, m, sum, carry;

	for (i = 0; n1[i]; i++)
		;
	for (j = 0; n2[j]; j++)
		;
	if (i > size_r || j > size_r)
		return (0);
	carry = 0;
	for (k = i - 1, l = j - 1, m = 0; k >= 0 || l >= 0; k--, l--, m++)
	{
		sum = carry;
		if (k >= 0)
			sum += n1[k] - '0';
		if (l >= 0)
			sum += n2[l] - '0';
		carry = sum / 10;
		if (m >= size_r)
			return (0);
		r[m] = sum % 10 + '0';
	}
	if (carry && m < size_r - 1)
	{
		r[m] = carry + '0';
		r[m + 1] = '\0';
	}
	else if (!carry && m <= size_r - 1)
	{
		r[m] = '\0';
	}
	else
	{
		return (0);
	}
	for (i = 0, j = m - 1; i < j; i++, j--)
	{
		sum = r[i];
		r[i] = r[j];
		r[j] = sum;
	}
	return (r);
}
