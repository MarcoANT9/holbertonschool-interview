#include "sort.h"

/**
 * max_num - Finds the maximum integer in an array.
 *
 * @array: Array to search max int.
 * @size: Size of the array.
 *
 *
 * Return: Maximum number in the array (int).
 *
 */
int max_num(int *array, int size)
{
	int i, max;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (max < array[i])
			max = array[i];
	}
	return (max);
}

/**
 * order - Sort the array digit.
 *
 * @array: Array of ints.
 * @size: Size of the array.
 * @tmp: Integer to find specific digits.
 *
 * Return: Nothing.
 */
void order(int *array, int size, int tmp)
{
	int i, *total, count[10] = {0};

	total = malloc(sizeof(int) * size);
	if (!total)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / tmp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		total[count[(array[i] / tmp) % 10] - 1] = array[i];
		count[(array[i] / tmp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = total[i];
	free(total);
}

/**
 * radix_sort - Sort an array of integers in ascending order
 *
 * @array: Array to be sorted.
 * @size: Size of array.
 *
 * Return: Nothing.
 */
void radix_sort(int *array, size_t size)
{
	int max, tmp;

	if (size < 2)
		return;
	for (max = max_num(array, size), tmp = 1; max / tmp > 0; tmp *= 10)
	{
		order(array, size, tmp);
		print_array(array, size);
	}

}
