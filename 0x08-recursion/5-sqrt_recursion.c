#include "main.h"

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root of the number
 * or -1 if n doesn't have a natural square root
 */

int _sqrt_recursion(int n)
{
	int start = 1, end = n, mid, sqrt;

	if (n < 0)
		return (-1);

	if (n == 0 || n == 1)
		return (n);

	while (start <= end)
	{
		mid = (start + end) / 2;
		sqrt = mid * mid;

		if (sqrt == n)
			return (mid);
		else if (sqrt < n)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return (-1);
}
