#include "main.h"

/**
 * _puts_recursion - Prints a string recursively
 * @s: Pointer to the string
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		return;
	}
	_putchar(*s);
	_puts_recursion(s + 1);
	_putchar('\n');

}
