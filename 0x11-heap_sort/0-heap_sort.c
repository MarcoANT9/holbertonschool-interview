#include "sort.h"

/**
 * pile - Find the largest number in a level.
 *
 *@array: Array of integers.
 *@size_max: Maximum size in iteration
 *@size: Original array size
 *@position: Root index
 *
 * Return: Noting (Void)
 */
void pile(int *array, size_t size_max, size_t size, size_t position)
{
	size_t tmp, left, right, value;

	tmp = position;
	left = 2 * position + 1;
	right = 2 * position + 2;

	if (left < size_max && array[left] > array[tmp])
		tmp = left;
	if (right < size_max && array[right] > array[tmp])
		tmp = right;
	if (tmp != position)
	{
		value = array[position];
		array[position] = array[tmp];
		array[tmp] = value;
		print_array(array, size);
		pile(array, size_max, size, tmp);
	}
}

/**
 * heap_sort - Sorts an array using the heap sort method.
 *
 * @array: Array of numbers to sort.
 * @size: Size of the array.
 *
 *
 * Description - This program uses the heap sort method to sort an array
 *               of numbers; heap sort is a comparison-based algorithm, it
 *               could be thought as an improved selection sort.
 *
 *
 * Return: Nothing (Void)
 *
 */
void heap_sort(int *array, size_t size)
{

	int top, tmp;

	if (!array || size < 1)
		return;
	for (tmp = size / 2 - 1; tmp >= 0; tmp--)
		pile(array, size, size, tmp);

	for (tmp = size - 1; tmp > 0; tmp--)
	{
		top = array[0];
		array[0] = array[tmp];
		array[tmp] = top;
		print_array(array, size);
		pile(array, tmp, size, 0);
	}
}
