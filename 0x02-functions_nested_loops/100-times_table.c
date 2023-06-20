#include "main.h"

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: The number of rows and columns in the table.
 *
 * Return: void
 */
void print_times_table(int n)
{
	int a, mul, result;

	if (n >= 0 && n <= 15)
	{
		for (a = 0; a <= n; a++)
		{
			_putchar('0');

			for (mul = 1; mul <= n; mul++)
			{
				_putchar(',');
				_putchar(',');

				result = a * mul;

				if (result <= 99)
					_putchar(' ');
				if (result <= 9)
					_putchar(' ');

				if (result >= 100)
				{
					_putchar((result / 100) + '0');
					_putchar(((result / 10)) % 10 + '0');
				}
				else if (result <= 99 && result >= 10)
				{
					_putchar((result / 10) + '0');
					_putchar((result % 10) + '0');
				}

				_putchar('\n');
			}
		}
	}
}

