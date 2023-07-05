#include "main.h"

int actual_sqrt_recursion(int n, int p);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate the square root of
 *
 * Return: the resulting square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (actual_sqrt_recursion(n, 0));
}

/**
 * actual_sqrt_recursion - recurses to find the natural
 * square root of a number
 * @n: number to calculate the square root of
 * @p: iterator
 *
 * Return: the resulting square root
 */
int actual_sqrt_recursion(int n, int p)
{
	if (p * p > n)
		return (-1);
	if (p * p == n)
		return (p);
	return (actual_sqrt_recursion(n, p + 1));
}
