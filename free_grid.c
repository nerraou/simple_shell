#include "main.h"

/**
 * free_grid - free a NULL terminated array
 * @grid: 2d array
*/
void free_grid(char **grid)
{
	int i;

	if (grid == NULL)
		return;
	for (i = 0; grid[i] != NULL; i++)
		free(grid[i]);
	free(grid);
}
