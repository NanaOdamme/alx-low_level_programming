#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints c
 * @args: argument for function
 */

void print_char(va_list args)
{
	int c = va_arg(args, int);
	printf("%c", c);
}

/**
 * print_int - prints intergers
 * @args: argument list
 */
void print_int(va_list args)
{
	int i;
	i = va_arg(args, int);
	printf("%d", i);
}

/**
 * print_float - prints float
 * @arg: argument list
 */
void print_float(va_list args)
{
	double f = va_arg(args, double);
	/*float gets promoted to double in varargs*/
	printf("%f", f);
}

/**
 * print_string - prints strings
 * @arg: argument list
 */
void print_string(va_list args)
{
	char *s = va_arg(args, char*);

	switch (s != NULL)
	{
		case 0:
			printf("(nil)");
			break;
			default:
			printf("%s", s);
	}
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 */
void print_all(const char * const format, ...)
{
	va_list args;
	va_start(args, format);

	/*Function pointer array for different format cases*/
	print_function print_functions[128] = { NULL };

	/*Assign function addresses to the corresponding format characters*/
	print_functions['c'] = print_char;
	print_functions['i'] = print_int;
	print_functions['f'] = print_float;
	print_functions['s'] = print_string;

	/*Loop through the format string and handle each type accordingly*/
	while (*format)
	{
		if (print_functions[*format] != NULL)
		{
		print_functions[*format](args);
		}
	}

	va_end(args);

	printf("\n");
}
