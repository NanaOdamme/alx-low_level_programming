#include "main.h"

/**
 * rot13 - Encodes a string using ROT13.
 * @str: The string to encode.
 *
 * Return: The encoded string.
 */
char *rot13(char *str)
{
	int i, j;
	char *letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_letters = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = rot13_letters[j];
			break;
			}
		}
	}

	return (str);
}
