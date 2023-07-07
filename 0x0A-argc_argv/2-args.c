#include <stdio.h>

/**
 * main - Prints all arguments received, each on a separate line
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0
 *
 */

int main(int argc, char *argv[])
{
	while (argc > 0)
	{
		printf("%s\n", *argv);
		argv++;
		argc--;
	}

	return (0);
}
