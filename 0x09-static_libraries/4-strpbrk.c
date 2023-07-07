#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the set of bytes to search for.
 *
 * Return: Pointer to the first matching byte or NULL if not found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		char *temp = accept;

		while (*temp != '\0')
		{
			if (*s == *temp)
			{
				return (s);
			}
				temp++;
		}
		s++;
	}
	return (NULL);
}
