#include "binary_trees.h"

/**
 * tree_builder - support function to build tree.
 *
 * @parent: Parent node pointer.
 * @array: Sorted array pointer.
 * @start: Start point index.
 * @end: Finish point index.
 *
 * Return: Pointer to root node of created tree.
 */
avl_t *tree_builder(avl_t *parent, int *array, size_t start, size_t end)
{
	avl_t *new_node;
	size_t i = (start + end) / 2;

	new_node = malloc(sizeof(avl_t));

	if (!new_node)
		return (NULL);

	new_node->n = array[i];
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	if (i != start)
		new_node->left = tree_builder(new_node, array, start, i - 1);
	if (i != end)
		new_node->right = tree_builder(new_node, array, i + 1, end);
	return (new_node);
}


/**
 * sorted_array_to_avl - This program transforms a sorted array into a AVL.
 *
 * @array: Sorted array to convert (int)
 * @size: Size of the array.
 *
 *
 * Description - This program takes a sorted array and transforms it into a AVL
 *               it returns the root of the newly created tree or NULL if some-
 *               thing fails.
 *
 *
 * Return: -> Root of the newly created tree.
 *         -> NULL on failure.
 *
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree;

	if (size == 0 || !array)
		return (NULL);

	tree = tree_builder(NULL, array, 0, size - 1);

	return (tree);
}
