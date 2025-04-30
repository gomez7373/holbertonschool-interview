#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print a 3x3 sandpile grid
 * @grid: 3x3 grid to print
 */
void print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_unstable - Check if the sandpile grid is unstable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if unstable, 0 otherwise
 */
int is_unstable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (1);
		}
	}
	return (0);
}

/**
 * topple - Topples the unstable sandpile
 * @grid: 3x3 sandpile grid to topple
 */
void topple(int grid[3][3])
{
	int temp[3][3] = {{0}}, i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				temp[i][j] -= 4;
				if (i > 0)
					temp[i - 1][j] += 1;
				if (i < 2)
					temp[i + 1][j] += 1;
				if (j > 0)
					temp[i][j - 1] += 1;
				if (j < 2)
					temp[i][j + 1] += 1;
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += temp[i][j];
		}
	}
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First 3x3 sandpile (result will be stored here)
 * @grid2: Second 3x3 sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Step 1: Add the two grids */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Step 2: Stabilize the result */
	while (is_unstable(grid1))
	{
		print_grid(grid1);
		topple(grid1);
	}
}

