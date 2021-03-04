#include "menger.h"

/**
 * charac - Checks the char to print.
 *
 * @i: number of columns.
 * @j: number of rows.
 *
 * Return: A character ('#' or ' ').
 */
char charac(int i, int j)
{
	for (; i && j; i /= 3, j /= 3)
		if (i % 3 == 1 && j % 3 == 1)
			return (' ');
	return ('#');
}



/**
 * menger - Creates a 2D menger
 *
 * @level: The level of menger to draw.
 *
 *
 * Return: Nothing (Void).
 *
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;
	size = pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%c", charac(i, j));
		printf("\n");
	}
}
