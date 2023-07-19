#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int b, count;
	char *array;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	b = atoi(argv[1]);

	if (b < 0)
	{
		printf("Error\n");
		exit(2);
	}

	array = (char *)main;

	count = 0;
	while (count < b)
	{
		if (count == b - 1)
		{
			printf("%02hhx\n", array[count]);
			break;
		}
		printf("%02hhx ", array[count]);
		count++;
	}

	return (0);
}
