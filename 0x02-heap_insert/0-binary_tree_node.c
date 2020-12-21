#include "binary_trees.h"

/**
 * binary_tree_node - Creates a node for a binary tree.
 *
 * @parent: Pointer to the parent of the node.
 * @value: Value to store inside the node.
 *
 *
 * Description - This function takes a pointer to the parent of the node and
 *               the value to store inside it and return a new node linked
 *               to the parent.
 *
 *
 * Return: -> Pointer to the newly created node.
 *         -> Null if anything fails.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);


}
