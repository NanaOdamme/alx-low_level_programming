#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: Pointer to the string to be searched.
 * @c: Character to be located.
 *
 * Return: Pointer to the 1st  occurranc of char or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}
