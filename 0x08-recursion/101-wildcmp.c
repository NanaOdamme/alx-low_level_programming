#include "main.h"

int wildcmp_recursive(char *s1, char *s2);

/**
 * wildcmp - Compare strings recursively
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: 1 if strings match, 0 if not
 */
int wildcmp(char *s1, char *s2)
{
	return (wildcmp_recursive(s1, s2));
}

/**
 * wildcmp_recursive - Compare strings recursively
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: 1 if strings match, 0 if not
 */
int wildcmp_recursive(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp_recursive(s1 + 1, s2 + 1));

	if (*s2 == '*')
	{
	if (*(s2 + 1) != '\0' && *s1 == '\0')
		return (wildcmp_recursive(s1, s2 + 1));

	return (wildcmp_recursive(s1 + 1, s2) || wildcmp_recursive(s1, s2 + 1));
	}

	return (0);
}

