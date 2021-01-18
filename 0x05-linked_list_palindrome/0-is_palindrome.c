#include "lists.h"

/**
 * reverse_list - Reverses a list.
 *
 * @head: Head of the list to reverse.
 *
 * Return: Nothing (void).
 */
void reverse_list(listint_t **head)
{
	listint_t *last = NULL, *current = *head, *supp;

	while (current)
	{
		supp = current->next;
		current->next = last;
		last = current;
		current = supp;
	}
	*head = last;
}


/**
 * is_palindrome - Verifies if a linked list is a palindrome.
 *
 * @head: Head of the linked list.
 *
 *
 *
 * Description - This function takes a single linked list and determines
 *               if its contents are a organized in palindrome manner, it
 *               returns 1 if the list is a palindrome (equivalent of true)
 *               or 0 if the list is not a palindrome (false).
 *
 * Return: -> 1 if the list is a palindrome.
 *         -> 0 if the list is not a palindrome.
 *
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head, *last = *head, *middle = NULL;

	if (head == NULL || *head == NULL)
		return (1);

	while (last)
	{
		last = last->next;
		if (last)
		{
			last = last->next;
			current = current->next;
		}
	}
	middle = current;
	reverse_list(&(middle->next));
	current = *head;
	last = middle->next;
	while (last)
	{
		if (current->n != last->n)
			return (0);
		current = current->next;
		last = last->next;
	}
	return (1);
}
