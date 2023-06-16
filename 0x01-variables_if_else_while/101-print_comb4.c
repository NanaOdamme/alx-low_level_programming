#include <stdio.h>

/**
 * main - Prints all possible different combinations of three digits.
 *
 * Return: Always 0.
 */
int main(void)
{
	int hundredsDigit;
	int tensDigit;
	int onesDigit;

	for (hundredsDigit = 0; hundredsDigit < 10; hundredsDigit++)
	{
		for (tensDigit = hundredsDigit + 1; tensDigit < 10; tensDigit++)
		{
			for (onesDigit = tensDigit + 1; onesDigit < 10; onesDigit++)
			{
				putchar(hundredsDigit + '0');
				putchar(tensDigit + '0');
				putchar(onesDigit + '0');

				if (hundredsDigit != 7 || tensDigit != 8 || onesDigit != 9)
				{
					putchar(',');
					putchar(' ');
				}
			}
		}
	}

	putchar('\n');

	return (0);
}
