#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - prints array elements on a new line
 * @array: array of elemnts
 * @size: num of elemnts to print
 * @action: pointer to function
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int count;

	while(count < size)
	{
		action(array[count]);
		count++;
	}
}
