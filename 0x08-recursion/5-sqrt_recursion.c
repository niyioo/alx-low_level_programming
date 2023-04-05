#include "main.h"

/**
 * _sqrt_helper - helper function for _sqrt_recursion
 * @n: the number to find the square root of
 * @start: the starting point for the binary search
 * @end: the ending point for the binary search
 *
 * Return: the natural square root of the number
 * or -1 if n doesn't have a natural square root
 */

int _sqrt_helper(int n, int start, int end)
{
	int mid, sqrt;

	if (n < 0) /* check for error: negative number */
		return (-1);

	if (n == 0 || n == 1) /* base case: square root of 0 or 1 is itself */
		return (n);

	if (start > end) /* base case: no square root found */
		return (-1);

	mid = (start + end) / 2;
	sqrt = mid * mid;

	if (sqrt == n) /* square root found */
		return (mid);
	else if (sqrt < n) /* search upper half of range */
		return (_sqrt_helper(n, mid + 1, end));
	else /* search lower half of range */
		return (_sqrt_helper(n, start, mid - 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: the number to find the square root of
 *
 * Return: the natural square root of the number
 * or -1 if n doesn't have a natural square root
 */

int _sqrt_recursion(int n)
{
	return (_sqrt_helper(n, 1, n));
}
