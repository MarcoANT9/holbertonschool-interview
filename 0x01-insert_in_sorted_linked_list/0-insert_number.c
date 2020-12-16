#include "lists.h"

/**
 * insert_node - Inserts a node in a sorted linked list
 *
 * @head: First node on the linked list
 * @number: Number to insert in the list
 *
 *
 * Description - This function takes a number and inserts it in the right
 *               position in the given linked list. It returns a pointer
 *               to the newly created node or Null if anything goes wrong.
 *
 *
 * Return: -> Pointer to the newly created node in the list.
 *         -> Null if there is an error.
 *
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current;

	if (new_node == NULL)
		return (NULL);
	new_node->n = number;
	if (head == NULL)
	{
		new_node = add_nodeint_end(head, number);
		*head = new_node;
		return (new_node);
	}
	current = *head;
	if (current == NULL)
	{
		new_node->next = NULL;
		return (new_node);
	}
	if (current->n > number)
	{
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}

	while (current->next->n < number && current->next->next != NULL)
	{
		current = current->next;
	}
	if (current->next !=  NULL)
		current = current->next;
	if (current->n < number)
		add_nodeint_end(head, number);
	else
	{
		new_node->next = current->next;
		current->next = new_node;
	}

	return (new_node);
}
