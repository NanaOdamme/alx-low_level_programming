#include <stdio.h>

/**
 * _sqrt_recursion2 - Recursive2 function to find the square root of n
 * @n: The number to find the square root of
 * @begin: The starting point of the search range
 * @close: The ending point of the search range
 *
 * Return: square of n, or -1 if n does not have a natural square
 */
int _sqrt_recursion2(int n, int begin, int close)
{
	int m;
	if (begin > close)
		return (-1);

	       m = (begin + close) / 2;

	if (m * m == n)
		return (m);

	if (m * m < n)
		return (_sqrt_recursion2(n, m + 1, close));
	else
		return (_sqrt_recursion2(n, begin, m - 1));
}

/**
 * _sqrt_recursion - Calculates the square of n
 * @n: The number to calculate the square root of
 *
 * Return: The square of n, or -1 if n is negative or does not have natural square
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return (_sqrt_recursion2(n, 1, n));
}
