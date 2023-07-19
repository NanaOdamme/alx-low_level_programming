#include "function_pointers.h"
#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"
/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int num1, num2;
	char *operators;
	int result;
	int (*operations)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		return (98);
	}

	num1 = atoi(argv[1]);
	operators = argv[2];
	num2 = atoi(argv[3]);

	operations = get_op_func(operators);


	if (operations == NULL)
	{
		printf("Error\n");
		return (99);
	}

	if ((*operators == '/' || *operators == '%') && num2 == 0)
	{
		printf("Error\n");
		return (100);
	}


	result = operations(num1, num2);
	printf("%d\n", result);

	return (0);
}
