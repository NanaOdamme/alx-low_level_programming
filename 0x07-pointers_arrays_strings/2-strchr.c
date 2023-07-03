#include "main.h"

/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */
char *_strchr(char *s, char c)
{
	int a = 0;

	while (s[a] >= '\0')
	{
		if (s[a] == c)
			return (&s[a]);
		a++;
	}
	return (0);
}
