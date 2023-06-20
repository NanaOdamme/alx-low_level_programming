#include "main.h"

/**
* print_times_table - Prints the n times table, starting with 0.
* @n: The number of rows and columns in the table.
*
* Return: void
*/
void print_times_table(int n)
{
	int i, j;

	if (n > 15 || n < 0)
	{
	return;
	}

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			int result = i * j;

			if (result > 999)
			{
				_putchar((result / 1000) + '0');
			}

		if (result > 99)
		{
			_putchar(((result / 100) % 10) + '0');
		}

		if (result > 9)
		{
			_putchar(((result / 10) % 10) + '0');
		}

			_putchar((result % 10) + '0');

		if (j != n)
		{
			_putchar(',');
			_putchar(' ');
		}
	}

		_putchar('\n');
	}
}
