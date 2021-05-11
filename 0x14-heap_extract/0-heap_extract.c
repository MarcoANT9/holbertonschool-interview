#include "binary_trees.h"

/**
 * tree_height - Calculates the height of a tree.
 *
 * @tree: Tree to measure (binary_tree_t *).
 *
 * Return: Height of the tree (size_t).
 */
static size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	left = 1 + tree_height(tree->left);
	right = 1 + tree_height(tree->right);

	if (right > left)
		return (right);
	return (left);
}

/**
 * swap_node - Swaps nodes to sort the tree.
 *
 * @node: Pointer to the heap root (heap_t *).
 *
 * Return: Pointer to the last node (heap_t).
 */
heap_t *swap_node(heap_t *node)
{
	int value;

	while (node->left || node->right)
	{
		if (node->right == NULL || node->left->n > node->right->n)
		{
			value = node->n;
			node->n = node->left->n;
			node->left->n = value;
			node = node->left;
		}
		else if (node->left == NULL || node->left->n < node->right->n)
		{
			value = node->n;
			node->n = node->right->n;
			node->right->n = value;
			node = node->right;
		}
	}

	return (node);
}

/**
 * order_tree - Pre-order traversal.
 *
 * @root: Root of the tree (heap_t *).
 * @node: Pointer to node in the tree (heap_t **).
 * @height: Height of the tree (size_t).
 * @level: Level at which the node is in the tree (size_t).
 *
 * Return: Nothing (Void).
 */
void order_tree(heap_t *root, heap_t **node, size_t height, size_t level)
{
	if (root != NULL)
	{
		if (height == level)
			*node = root;

		level++;

		if (root->left != NULL)
			order_tree(root->left, node, height, level);

		if (root->right != NULL)
			order_tree(root->right, node, height, level);
	}
}

/**
 * heap_extract - Exxtracts the root of a binary tree.
 *
 * @root: Root of the binary tree.
 *
 *
 * Description - This function extracts the root ode of a Max Binary Heap,
 *               it frees the node, recplace it with the last level-order node
 *               and returns the stored value.
 *
 * Return: -> Value stored in the original root node on success (int).
 *         -> 0 on failure (int).
 */
int heap_extract(heap_t **root)
{
	heap_t *node, *tmp;
	size_t height;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	tmp = *root;
	value = tmp->n;
	if (tmp->left == NULL && tmp->right == NULL)
	{
		free(*root);
		return (value);
	}

	height = tree_height(tmp);
	order_tree(tmp, &node, height, 0);
	tmp = swap_node(tmp);
	tmp->n = node->n;

	if (node->parent->right != NULL)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;

	free(node);
	return (value);
}
