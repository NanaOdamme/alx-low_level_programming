#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, j, x, len, f, digit;

	i = 0;
	j = 0;
	x = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++j;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (j % 2)
			{
				digit = -digit;
			}
				x = x * 10 + digit;
				f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
	return (0);

	return (x);
}

/**
 * main - Multiplies two numbers and prints the result
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 if successful, 1 if error
 */

int main(int argc, char *argv[])
{
	int number1;
	int number2;
	int result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	number1 = atoi(argv[1]);
	number2 = atoi(argv[2]);

	result = number1 * number2;

	printf("%d\n", result);

	return (0);
}
