#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 *
 * Description - This is the main function, it inserts a node into the
 *               Max Binary Heap. It returns the address to the newly
 *               created node or NULL if something fails.
 *
 *
 * Return: -> The address to the newly created node.
 *         -> NULL if something fails.
 *
 */
heap_t *heap_insert(heap_t **root, int value)
{

	heap_t *current_node;

	current_node = binary_tree_node(*root, value);

	if (*root == NULL)
		*root = current_node;
	else
	{
		if (current_node->left == NULL && current_node->parent->n < current_node->n)
		{
			current_node->parent->left = current_node;
			current_node->parent->n = current_node->n;
			current_node = current_node->parent;
		}
		else
			current_node->parent->right = current_node;
	}
	return (current_node);
}
