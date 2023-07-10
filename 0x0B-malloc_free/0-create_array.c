#include "main.h"
#include <stdlib.h>
/**
 * create_array - create array of size size and assign char c
 * @size: size of array
 * @c: char to assign
 * Description: create array of size size and assign char c
 * Return: pointer to array, NULL if fail
 *
 */
char *create_array(unsigned int size, char c)
{
	char *a;
	unsigned int ind;

	a = malloc(sizeof(char) * size);
	if (size == 0 || a == NULL)
		return (NULL);

	ind = 0;
	while (ind < size)
	{
		a[ind] = c;
		ind++;
	}

	return (a);
}
