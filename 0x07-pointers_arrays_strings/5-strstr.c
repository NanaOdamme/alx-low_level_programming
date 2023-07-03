#include "main.h"

/**
 * _strstr - Locates a substring.
 * @haystack: Pointer to the string to be searched.
 * @needle: Pointer to the substring to search for.
 *
 * Return: Pointer to the beginning of the located substring, or NULL if not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *h = haystack;
		char *n = needle;

		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
		}

		if (*n == '\0')
		{
			return (haystack);
		}

		haystack++;
	}

	return (NULL);
}
