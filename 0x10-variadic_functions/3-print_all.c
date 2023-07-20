#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int count = 0;
	char *string;
	char *comma = "";
	va_list args;

	va_start(args, format);

	if (format)
	{
		while (format[count] != '\0')
		{
			switch (format[count])
			{
				case 'c':
					printf("%s%c", comma, va_arg(args, int));
					break;
				case 'i':
					printf("%s%d", comma, va_arg(args, int));
					break;
				case 'f':
					printf("%s%f", comma, va_arg(args, double));
					break;
				case 's':
					string = va_arg(args, char *);
					if (!string)
					string = "(nil)";
					printf("%s%s", comma, string);
					break;
				default:
					count++;
					continue;
			}
			comma = ", ";
			count++;
		}
	}

	printf("\n");
	va_end(args);
}
