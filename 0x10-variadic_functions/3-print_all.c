#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	int count;
	char *string, *separator;
	va_list myvar_types;

	va_start(myvar_types, format);

	separator = "";

	count = 0;
	if (format)
	{
		while (format[count])
		{
			switch (format[count])
			{
				case 'c':
				printf("%s%c", separator, va_arg(myvar_types, int));
				break;

				case 'i':
				printf("%s%d", separator, va_arg(myvar_types, int));
				break;

				case 'f':
				printf("%s%f", separator, va_arg(myvar_types, double));
				break;

				case 's':
				string = va_arg(myvar_types, char *);

				if (!string)
				{
					string = "(nil)";
					printf("%s%s", separator, string);
				}
				break;
				default:
				count++;
				continue;
			}
			separator = ", ";
			count++;
		}
	}

		printf("\n");
		va_end(myvar_types);
}
