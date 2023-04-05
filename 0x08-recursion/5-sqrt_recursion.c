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
	long int mid, sqrt;

	if (end < start)
		return (-1);

	mid = (start + end) / 2;
	sqrt = mid * mid;

	if (sqrt == n)
		return (mid);
	else if (sqrt < n)
		return (_sqrt_helper(n, mid + 1, end));
	else
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
	if (n < 0)
		return (-1);
	else
		return (_sqrt_helper(n, 0, n));
}
