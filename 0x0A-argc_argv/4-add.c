#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * PositiveNum - Checks if a string represents a positive number
 * @a: String to be checked
 *
 * Return: 1 if positive number, 0 otherwise
 */
int PositiveNum(char *amp)
{
	while (*amp != '\0')
	{
		if (!isdigit(*amp))
	{
		return (0);
	}
		amp++;
	}
	return (1);
}

/**
 * main - Adds positive numbers and prints the result
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
	int result = 0;
	int ind = 1;
	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	while (ind < argc)
	{
		if (PositiveNum(argv[ind]))
	{
		result += atoi(argv[ind]);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
		ind++;
	}

	printf("%d\n", result);

	return (0);
}
