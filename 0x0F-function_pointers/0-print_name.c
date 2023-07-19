#include "function_pointers.h"

/**
 * print_name - prints name
 * @name: name string
 * @f: pointer to the function
 * Return: void
 * */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}
