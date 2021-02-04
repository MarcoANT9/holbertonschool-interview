#include "lists.h"

/**
 * check_cycle - Checks if a linked list has a cycle in it.
 *
 * @list: Head of the linked list.
 *
 *
 *
 * Description - This program takes the head of a linked list and determines if
 *               it has a cycle or not.
 *
 * Return: -> 1 if the linked list has a cycle.
 *         -> 0 if the linked list has no cycle.
 *
 */
int check_cycle(listint_t *list)
{

	listint_t *conejo = list, *tortuga = list;

	if (conejo->next == NULL)
		return (0);

	while (conejo != NULL)
	{
		conejo = conejo->next;
		if (conejo == tortuga)
			return (1);
		if (conejo != NULL)
			conejo = conejo->next;
		tortuga = tortuga->next;
	}
	return (0);
}
