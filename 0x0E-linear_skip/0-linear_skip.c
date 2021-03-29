#include "search.h"

/**
 * linear_skip - Searches for an element in a skip list.
 *
 * @list: Pointer to the start of a sorted skip list.
 * @value: Value to search in the sorted skip list.
 *
 *
 * Description - This program takes a sorted skip linked list and
 *               searches for a given value, to save time and processing
 *               capacity, the linked list has "express lanes" to further
 *               elements within it.
 *
 * Return: -> The node of the link that contains the searched value on success.
 *         -> NULL if the linked list is NULL or doesn't contain the searched
 *            value.
 *
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp = list, *save;

	if (list == NULL)
		return (NULL);

	save = tmp->express;
	while (save)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       save->index, save->n);

		if (save->n >= value)
			break;
		tmp = save;
		if (save->express == NULL)
		{
			while (save->next)
				save = save->next;
			break;
		}
		save = save->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       tmp->index, save->index);
	while (tmp && tmp->index <= save->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", tmp->index,
		       tmp->n);
		if (tmp->n == value)
		{
			return (tmp);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
