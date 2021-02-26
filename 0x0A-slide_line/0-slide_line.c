#include "slide_line.h"

/**
 * slide_line - Recreates the slide mechanic of the 2048 game.
 *
 * @line: List to swipe.
 * @size: Size of the line.
 * @direction: Direction at which the swipe is made (left or right).
 *
 * Description - This program recreates the swipe mechanic from the game
 *               2048, it can swipe left or right, if the program checks two
 *               numbers with the same value, it adds them together.
 *
 * Return: -> 1 on success.
 *         -> 0 on failure.
 *
 */
int slide_line(int *line, size_t size, int direction)
{
	int size_copy = size;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	switch (direction)
	{
	case SLIDE_LEFT:
		left_swipe(line, size_copy);
		break;
	case SLIDE_RIGHT:
		right_swipe(line, size_copy);
		break;
	}

	return (1);
}

/**
 * left_swipe - for left swiping.
 *
 * @line: List to swipe.
 * @size_copy: Size of the line.
 *
 * Return: Nothing (Void).
 */
void left_swipe(int *line, int size_copy)
{
	int i, j = 0, aux = line[0];

	for (i = 0; i < size_copy; i++)
	{
		if (line[i])
		{
			if (i != 0)
			{
				if (line[i] == aux)
				{
					line[j] = line[i] + aux;
					aux = 0;
					j++;
				}
				else
				{
					if (aux != 0)
					{
						line[j] = aux;
						j++;
					}
					if (i == size_copy - 1)
					{
						line[j] = line[i];
						j++;
					}
					aux = line[i];
				}
			}
		}
	}
	if (j == 0)
	{
		line[j] = aux;
		j++;
	}
	for (; j < size_copy; j++)
		line[j] = 0;
}

/**
 * right_swipe - for left swiping.
 *
 * @line: List to swipe.
 * @size_copy: Size of the line.
 *
 * Return: Nothing (Void).
 */
void right_swipe(int *line, int size_copy)
{
	int i, j = size_copy - 1, sup = line[j];

	for (i = size_copy - 1; i >= 0; i--)
	{
		if (line[i])
		{
			if (i != sup - 1)
			{
				if (line[i] == sup)
				{
					line[j] = line[i] + sup;
					sup = 0;
					j--;
				}
				else
				{
					if (sup != 0)
					{
						line[j] = sup;
						j--;
					}
					if (i == 0)
					{
						line[j] = line[i];
						j--;
					}
					sup = line[i];
				}
			}
		}
	}
	if (j == size_copy - 1)
	{
		line[j] = sup;
		j--;
	}
	for (; j >= 0; j--)
		line[j] = 0;

}
