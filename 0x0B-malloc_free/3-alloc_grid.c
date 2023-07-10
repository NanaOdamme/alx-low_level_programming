#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - create a 2D grid using nested loops
 * @width: width input
 * @height: height input
 *
 * Return: pointer to a 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **yada;
	int q = 0, w = 0;

	if (width <= 0 || height <= 0)
		return (NULL);

	yada = malloc(sizeof(int *) * height);
	if (yada == NULL)
		return (NULL);

	while (q < height)
	{
		yada[q] = malloc(sizeof(int) * width);
		if (yada[q] == NULL)
		{
			while (q >= 0)
			{
				free(yada[q]);
				q--;
			}
			free(yada);
			return (NULL);
		}
		q++;
	}

	q = 0;
	while (q < height)
	{
		w = 0;
		while (w < width)
		{
			yada[q][w] = 0;
			w++;
		}
		q++;
	}

	return (yada);
}

