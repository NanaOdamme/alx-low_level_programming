#include "main.h"

int Palindrome(char *s, int a, int l);
int _strlen_recursion(char *s);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if it is a palindrome, 0 if it is not
 */
int is_palindrome(char *s)
{
	int len;

	if (*s == '\0')
		return (1);

	len = _strlen_recursion(s);
	return (Palindrome(s, 0, len));
}

/**
 * _strlen_recursion - Calculates the length of a string recursively
 * @s: Pointer to the string
 *
 * Return: Length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	return (0);
	return (1 + _strlen_recursion(s + 1));
}

/**
 * Palindrome - checks if a string is a palindrome recursively
 * @s: string to check
 * @a: starting index
 * @l: ending index
 *
 * Return: 1 if it is a palindrome, 0 if it is not
 */
int Palindrome(char *s, int a, int l)
{
	if (*(s + a) != *(s + l - 1))
		return (0);

	if (a >= l)
		return (1);

	return (Palindrome(s, a + 1, l - 1));
}
