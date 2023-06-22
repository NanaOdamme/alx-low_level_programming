#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a given number
 * @n: The number to find the largest prime factor of
 *
 * Return: The largest prime factor of the number
 */

unsigned long largest_prime_factor(unsigned long n)
{
	unsigned long i, largest_factor;

	largest_factor = 1;

	/* Divide the number by 2 until it's no longer divisible by 2 */
	while (n % 2 == 0)
	{
		largest_factor = 2;
		n = n / 2;
	}

	/* Check for prime factors starting from 3 up to the square root of n */
	for (i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n % i == 0)
		{
			largest_factor = i;
			n = n / i;
		}
	}

	/* If n is still greater than 2, it is a prime factor */
	if (n > 2)
		largest_factor = n;

	return (largest_factor);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 (Success)
 */
int main(void)
{
	unsigned long number = 612852475143;
	unsigned long largest_factor;

	largest_factor = largest_prime_factor(number);

	printf("%lu\n", largest_factor);

	return (0);
}

