#include <stdlib.h>
#include "main.h"

/**
 * *array_range - creates an array of integers
 * @min: minimum range of values stored
 * @max: maximum range of values stored and number of elements
 *
 * Return: pointer to the new array
 */
int *array_range(int min, int max)
{
	int *a;
	int ind, s;

	if (min > max)
		return (NULL);

	s = max - min + 1;

	a = malloc(s * sizeof(int));

	if (a == NULL)
		return (NULL);

	ind = 0;
	while (min <= max)
	{
		a[ind] = min++;
		ind++;
	}

	return (a);
}
