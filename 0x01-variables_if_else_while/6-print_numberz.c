#include <stdio.h>

/**
 * main - Prints single-digit numbers of base 10, starting from 0,
 *        followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int number;

	for (number = 0; number < 10; number++)
	{
		putchar(number + '0');
	}

	putchar('\n');

	return (0);
}
