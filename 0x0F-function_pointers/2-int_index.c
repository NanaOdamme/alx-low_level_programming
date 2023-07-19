#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: pointer to an integer array
 * @size: num of elements in the array
 * @cmp: pointer to a functio
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int count = 0;

	if (size <= 0)
	{
		return (-1);
	}

	while (count < size)
	{
		if(cmp(array[count]))
		{
			return (count);
		}
		count++;
	}
		return (-1);
}
