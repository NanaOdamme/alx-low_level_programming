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
	unsigned int result;

	if (b == NULL)
		return (0);

	result = 0;

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0); /* Invalid character found, return 0 as error indicator */

		result = (result << 1) + (*b - '0');
		b++; /* Move to the next character in the string */
	}

	return (result);
}
