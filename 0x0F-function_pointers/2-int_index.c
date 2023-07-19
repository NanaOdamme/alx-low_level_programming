#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: pointer to an integer array
 * @size: num of elements in the array
 * @cmp: pointer to a function
 * Return: If an integer is found, the index of the first occurrence
 *         of the integer in the array. Otherwise, -1 if any of the
 *         following conditions is met:
 *         - The array is NULL.
 *         - The size is less than or equal to 0.
 *         - The cmp function is NULL.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int count = 0;

	if (array == NULL || size <= 0 || cmp == NULL)
	{
		return (-1);
	}

	while (count < size)
	{
		if (cmp(array[count]))
		{
			return (count);
		}
		count++;
	}
		return (-1);
}
