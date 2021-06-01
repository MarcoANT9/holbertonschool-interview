#include "lists.h"

/**
 * find_listint_loop - Finds a loop inside a linked list.
 *
 * @head: Head of the linked list.
 *
 *
 * Description - This program uses the "hare" and "turtle" method to
 *               determine if a linked list has a loop in it.
 *
 * Return: -> Address of the node in which the loop starts on success.
 *         -> NULL on failure.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *hare, *turtle;

	if (head == NULL)
		return (NULL);

	turtle = head->next;
	hare = turtle->next;

	while (turtle && hare && hare->next)
	{
		if (turtle == head || hare == head)
			return (head);

		if (hare == turtle && hare != head)
		{
			head = head->next;
			hare = head;
			turtle = head;
		}
		turtle = turtle->next;
		hare = hare->next->next;
	}
	return (NULL);
}
