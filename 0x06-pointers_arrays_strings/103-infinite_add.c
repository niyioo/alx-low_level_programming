#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: The first number to add
 * @n2: The second number to add
 * @r: The buffer to store the result
 * @size_r: The buffer size
 *
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i = 0, j = 0, l1 = 0, l2 = 0, sum = 0, carry = 0;

	while (n1[l1] != '\0')
		l1++;
	while (n2[l2] != '\0')
		l2++;
	if (l1 > size_r || l2 > size_r || size_r == 0)
		return (0);
	l1--;
	l2--;
	r[size_r - 1] = '\0';
	for (i = size_r - 2; l1 >= 0 || l2 >= 0; i--)
	{
		sum = carry;
		if (l1 >= 0)
			sum += n1[l1--] - '0';
		if (l2 >= 0)
			sum += n2[l2--] - '0';
		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		r[i] = sum + '0';
	}
	if (carry == 1)
	{
		if (i == 0)
			return (0);
		r[--i] = '1';
	}
	for (j = 0; r[i] != '\0'; j++, i++)
	{
		if (j >= size_r)
			return (0);
		r[j] = r[i];
	}
	r[j] = '\0';

	return (r);
}
