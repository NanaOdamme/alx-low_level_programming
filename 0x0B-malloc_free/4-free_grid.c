#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * free_grid_recursive - frees 2D array recursively
 * @grid: 2D array to be freed
 * @height: height dimension of grid
 * @ind: current index of the grid
 *
 * Description: Frees the memory of a 2D array recursively
 */
void free_grid_recursive(int **grid, int height, int ind)
{
	if (ind >= height)
	{
		free(grid);
		return;
	}

	free(grid[ind]);
	ind++;
	free_grid_recursive(grid, height, ind);
}

/**
 * free_grid - frees 2D array
 * @grid: 2D array to be freed
 * @height: height dimension of grid
 *
 * Description: Frees the memory of a 2D array
 */
void free_grid(int **grid, int height)
{
	int ind = 0;

	if (grid == NULL)
		return;

	while (ind < height)
	{
		free(grid[ind]);
		ind++;
	}
	free(grid);
}
