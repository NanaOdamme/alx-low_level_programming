#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A pointer to a string of 0 and 1 characters.
 *
 * Return: The converted number, or 0
 * if there is one or more chars in the string b
 *         that is not 0 or 1, or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value = 0;

	if (b == NULL)
	{
	return (0);
	}

	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}

	value += (1 << i) * (b[i] - '0');
	}

	return (value);
}

