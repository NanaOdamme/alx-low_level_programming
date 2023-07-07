#include <stdio.h>

/**
 * main - Prints the name of the program
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	char *pN = argv[0];

	printf("%s\n", pN);

	return (0);
}
