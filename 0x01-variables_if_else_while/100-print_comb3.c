#include <stdio.h>

/**
 * main - Prints all possible different combinations of two digits.
 *
 * Return: Always 0.
 */
int main(void)
{
	int tensDigit;
	int onesDigit;

	for (tensDigit = 0; tensDigit < 10; tensDigit++)
	{
		for (onesDigit = tensDigit + 1; onesDigit < 10; onesDigit++)
		{
			putchar(tensDigit + '0');
			putchar(onesDigit + '0');

			if (tensDigit != 8 || onesDigit != 9)
			{
				putchar(',');
				putchar(' ');
			}
		}
	}

	putchar('\n');

	return (0);
}
