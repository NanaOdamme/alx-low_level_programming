#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the resulting string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int lengths1 = 0, lengths2 = 0, i = 0, j = 0;
	char *memory;

	if (s1 == NULL && s2 == NULL)
	{
		s1 = " ";
		s2 = " ";
	}
	while (s1[lengths1] != '\0')
		lengths1++;

	while (s2[lengths2] != '\0')
		lengths2++;

	if (n >= lengths2)
	{
		memory = malloc((lengths1 + n + 1) * sizeof(char));
	}
	else
	{
		memory = malloc((lengths1 + lengths2 + 1) * sizeof(char));
	}
	if (memory == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		memory[i] = s1[i];
		i++;
	}
	while (j < n && s2[j] != '\0')
	{
		memory[i] = s2[j];
		i++;
		j++;
	}

	memory[i] = '\0';
	return (memory);
}
