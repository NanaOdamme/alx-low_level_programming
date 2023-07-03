#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - Entry point
 * @a: input
 * @size: input
 * Return: Always 0 (Success)
 */
void print_diagsums(int *a, int size)
{
	int sum1 = 0;
	int sum2 = 0;
	int y = 0;

	// Calculate sum1 along the diagonal from top-left to bottom-right
	while (y < size)
	{
		sum1 = sum1 + a[y * size + y];
		y++;
	}

	y = size - 1;

	// Calculate sum2 along the diagonal from top-right to bottom-left
	while (y >= 0)
	{
		sum2 += a[y * size + (size - y - 1)];
		y--;
	}

	printf("%d, %d\n", sum1, sum2);
}
