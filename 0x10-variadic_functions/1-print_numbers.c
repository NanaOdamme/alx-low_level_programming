#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_numbers - prints numbers
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the func
 * @...:variable number of arguments
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list myNum;
	int numbers;
	unsigned int count;


	va_start(myNum, n);

	count = 0;
	while (count < n)
	{
		numbers = va_arg(myNum, int);

		printf("%d", numbers);

		if (separator != NULL && count < n - 1)
		{
			printf("%s", separator);
		}
		count++;
	}

	va_end(myNum);

	printf("\n");
}
