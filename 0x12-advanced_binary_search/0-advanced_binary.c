#include "search_algos.h"

/**
 * search_value - Support function to search the required value.
 *
 * @array: Array to search.
 * @first_index: First index in the sub-array.
 * @last_index: Last index of the sub-array.
 * @value: Searched Value.
 *
 * Return: -> Position in which the first value is found (Int).
 *         -> -1 if the value is not found.
 */
int search_value (int *array, size_t first_index, size_t last_index, int value)
{
	size_t i = first_index, position;

	if (first_index == last_index)
		return (-1);

	printf("Searching in array: ");

	while (i < last_index)
	{
		if (i != first_index)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");

	position = (first_index + last_index - 1) / 2;

	if (array[position] == value)
	{
		if (array[position - 1] < value)
			return (position);
		return (search_value(array, first_index, position + 1, value));
	}

	if (array[position] < value)
		return (search_value(array, position + 1, last_index, value));
	else if (array[position] > value)
		return (search_value(array, first_index, position + 1, value));
	return (-1);

}


/**
 * advanced_binary - Advanced binary search algorithm.
 *
 * @array: Array of sorted numbers to search.
 * @size: Size of the array.
 * @value: Value to search in the array.
 *
 *
 * Description - This algorithm uses an advanced version of the binary search
 *               method, this is to locate the first ocurrence of a number even
 *               if it appears more than once in the array.
 *
 *
 * Return: -> Location of the first ocurrence of the searched value (Int).
 *         -> -1 on failure.
 *
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);

	return (search_value(array, 0, size, value));
}
