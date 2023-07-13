#include "main.h"
#include <stdlib.h>

/**
 *malloc_checked - allocates memory using malloc
 *@b: number of bytes to allocate
 *
 *Return: returns a pointer s
 */

void *malloc_checked(unsigned int b)
{
	void *s;

	s = malloc(b);
	if (s == NULL)
		exit(98);

	return (s);
}
