#include "sort.h"

/**
 * merge_sub - Support function.
 * @array: Complete array to sort.
 * @listR: Right part of the list.
 * @listL: Left part of the list.
 * @size: Size of the array.
 *
 * Return: Nothing (Void).
 */
void merge_sub(int *array, int *listR, int *listL, size_t size)
{
	int i = 0, j = 0, s = 0;
	int leftCount = size / 2, rightCount = size - leftCount;

	while (i < leftCount && j < rightCount)
	{
		if (listL[i] <= listR[j])
		{
			array[s] = listL[i];
			i++;
		}
		else
		{
			array[s] = listR[j];
			j++;
		}
		s++;
	}
	while (i < leftCount)
	{
		array[s] = listL[i];
		i++;
		s++;
	}
	while (j < rightCount)
	{
		array[s] = listR[j];
		j++;
		s++;
	}
	printf("Merging...\n");
	printf("[Left]: ");
	print_array(listL, leftCount);
	printf("[right]: ");
	print_array(listR, rightCount);
	printf("[Done]: ");
	print_array(array, size);

}

/**
 * merge_sort - Sorts an array with the merge method.
 *
 * @array: Array to sort.
 * @size: Size of the array.
 *
 *
 * Return: Nothing (Void).
 *
 */
void merge_sort(int *array, size_t size)
{
	int *listR, *listL;
	size_t mid = size / 2, position;


	listR = (int *) malloc(size);
	listL = (int *) malloc(size);
	if (size < 2 || array == NULL)
		return;

	for (position = 0; position < mid; position++)
		listL[position] = array[position];

	for (position = mid; position < size; position++)
		listR[position - mid] = array[position];

	merge_sort(listL, mid);
	merge_sort(listR, size - mid);
	merge_sub(array, listR, listL, size);
	free(listL);
	free(listR);
}
