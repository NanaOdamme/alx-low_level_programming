#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - Calculates the sum of multiple integer parameters.
 * @n: The number of parameters.
 * @...: A variable number of integer parameters to sum.
 *
 * Return: The sum of all the provided integer parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	va_list myNums;
	unsigned int count;
	int result = 0;

	if (n == 0)
	{
		return (0);
	}


	va_start(myNums, n);

	count = 0;
	while (count < n)
	{
		result += va_arg(myNums, int);
		count++;
	}

	va_end(myNums);

	return (result);
}
