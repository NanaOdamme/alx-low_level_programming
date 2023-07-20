#include "variadic_functions.h"
#include <stdarg.h>

/**
 * print_strings - prints strings followed by new line
 * @separator: string to be printed
 * @n: number of strings passed to func
 * @...: variable number of arg
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	const char *printed_string;
	unsigned int count;

	va_list myString;

	va_start(myString, n);

	count = 0;
	while (count < n)
	{
		printed_string = va_arg(myString, const char*);

		if (printed_string == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", printed_string);
		}
		if (separator != NULL && count < n - 1)
		{
			printf("%s", separator);
		}
		count++;
	}

	va_end(myString);

	printf("\n");
}
