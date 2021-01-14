#include "sandpiles.h"

/**
 * is_balanced - Determines if a grid is balanced.
 *
 * @grid: A 3x3 grid, may not be balanced.
 *
 *
 *
 * Description - This function takes a grid and detemines if it is balanced or
 *               not, to be balanced all elements must be less than 4. Returns
 *               1 if the grid is balanced or 0 if it is not.
 *
 *
 * Return: -> 1 if the grid is balanced.
 *         -> 0 if the grid is not balanced.
 *
 */
int is_balanced(int grid[3][3])
{
	int i;
	int j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * balance_grid - Function used to try to balance the grid.
 *
 * @grid: 3x3 unbalanced matrix.
 *
 */
void balance_grid(int grid[3][3])
{
	int i, j;
	int copy[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				copy[i][j] += grid[i][j] - 4;
				if (i - 1 >= 0)
					copy[i - 1][j]++;
				if (i + 1 < 3)
					copy[i + 1][j]++;
				if (j - 1 >= 0)
					copy[i][j - 1]++;
				if (j + 1 < 3)
					copy[i][j + 1]++;

			}
			else
				copy[i][j] += grid[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid[i][j] = copy[i][j];
	}
}


/**
 * sandpiles_sum - Sums two sandpiles.
 *
 * @grid1: A 3x3 grid, may not be balanced.
 * @grid2: A 3x3 grid, may not be balanced.
 *
 *
 * Description - This function takes two grids and sums them together according
 *               to normal matrix arithmetics, if any element of the resulting
 *               grid is greather than 4, 1 has to be summed to all neighboring
 *               elements, if the element can't be summed (like in a corner or
 *               side) the 1 is discarted. This function returns nothing.
 *
 *
 * Return: -> Nothing.
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];
	}

	while (is_balanced(grid1) == 0)
	{
		printf("=\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid1[i][j]);
			}
			printf("\n");
		}
		balance_grid(grid1);
	}

}
