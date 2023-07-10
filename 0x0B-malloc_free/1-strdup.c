#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: char
 * Return: pointer to duplicated string, or NULL on failure
 */
char *_strdup(char *str)
{
	char *ptr;
	int ind, rnd = 0;

	if (str == NULL)
		return (NULL);

	ind = 0;
	while (str[ind] != '\0')
		ind++;

	ptr = malloc(sizeof(char) * (ind + 1));
	if (ptr == NULL)
		return (NULL);

	while (rnd < ind)
	{
		ptr[rnd] = str[rnd];
		rnd++;
	}

	ptr[ind] = '\0';  /* Add null terminator */

	return (ptr);
}
