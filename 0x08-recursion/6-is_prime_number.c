#include "main.h"

/**
 * Divisible - function that checks if n is divisible by smaller numbers
 * @n: The number to be checked.
 * @ab: The divisor.
 *
 * Return: 1 if n is a prime number, 0 otherwise.
 */
int Divisible(int n, int ab)
{
	if (ab == 1)
		return (1);
	if (n % ab == 0)
		return (0);
	return (Divisible(n, ab - 1));
}

/**
 * is_prime_number - Checks if a number is a prime number.
 * @n: The number to be checked.
 *
 * Return: 1 if n is a prime number, 0 otherwise.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (Divisible(n, n - 1));
}
