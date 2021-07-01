#include "list.h"

/**
 * create_list - Creates a node that references itself.
 *
 * @list: List to store the created node.
 * @str: String to input in de created node.
 *
 * Description - This support function is only called if the linked list
 *               passed on add node end (or beginning) is NULL, it will
 *               create a new node that references itself in both "next"
 *               and "prev" directions.
 *
 * Return: -> New node that references itself (List *node) on success.
 *         -> NULL on failure.
 */
List *create_list(List **list, char *str)
{
	List *new_node;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = new_node;
	new_node->prev = new_node;
	*list = new_node;
	return (new_node);
}

/**
 * add_node_end - Adds a node at the end of a list.
 *
 * @list: Head of the list to add a node.
 * @str: String to input in the added node.
 *
 *
 * Description - This function adds a new element at the end of the selected
 *               linked list, if the list is empty (list = NULL), it will
 *               instead create a new double cicular linked list with the
 *               created node as its only element.
 *
 * Return: -> Address of the newly created node (List *node) on success.
 *         -> NULL on failure.
 *
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *head;

	if (!list || !str)
		return (NULL);

	if (*list == NULL)
	{
		new_node = create_list(list, str);
		return (new_node);
	}
	head = *list;
	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = head;
	new_node->prev = head->prev;
	head->prev->next = new_node;
	head->prev = new_node;
	return (new_node);
}

/**
 * add_node_begin - Adds a node at the beginning of a list.
 *
 * @list: Head of the list to add a node.
 * @str: String to input in the added node.
 *
 *
 * Description - This function adds a new element at the beginning of the
 *               selected linked list, if the list is empty (list = NULL),
 *               it will instead create a new double cicular linked list with
 *               the created node as its only element.
 *
 * Return: -> Address of the newly created node (List *node) on success.
 *         -> NULL on failure.
 *
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *head;


	if (!list || !str)
		return (NULL);

	if (*list == NULL)
	{
		new_node = create_list(list, str);
		return (new_node);
	}
	head = (*list)->prev;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	new_node->prev = head;
	new_node->next = *list;
	(*list)->prev = head->next = new_node;
	*list = new_node;
	return (new_node);
}
