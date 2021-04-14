#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: Size of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (!tree)
		return (0);
	if (tree->left != NULL)
		size = size + binary_tree_size(tree->left);
	if (tree->right != NULL)
		size = size + binary_tree_size(tree->right);
	return (size);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (binary_tree_size(tree->left) == binary_tree_size(tree->right))
		return (1);
	return (0);
}

/**
 * heap_parent_vs_child - swaps parent node if is greater than child node
 * @son: pointer to child node
 * @father: pointer to parent node
 * Return: nothing
 */
void heap_parent_vs_child(heap_t **son, heap_t **father)
{
	heap_t *c_left, *c_right, *child = *son, *parent = *father;

	c_right = (*son)->right, c_left = (*son)->left;

	if (child->n > parent->n)
	{
		if (child->left)
			child->left->parent = parent;
		if (child->right)
			child->right->parent = parent;
		if (parent->left == child)
		{
			if (parent->right)
				parent->right->parent = child;
			child->right = parent->right;
			child->left = parent;
		}
		else
		{
			parent->left->parent = child;
			child->left = parent->left;
			child->right = parent;
		}
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = child;
			else
				parent->parent->right = child;
		}
		else
		{
			*father = child;
		}
		child->parent = parent->parent;
		parent->parent = child;
		parent->left = c_left;
		parent->right = c_right;
	}
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_is_perfect(*root) || (!binary_tree_is_perfect((*root)->left)))
	{
		if ((*root)->left != NULL)
		{
			new = heap_insert(&((*root))->left, value);
			heap_parent_vs_child(&((*root)->left), root);
			return (new);
		}
		else
		{
			new = binary_tree_node(*root, value);
			(*root)->left = new;
			heap_parent_vs_child(&((*root)->left), root);
			return (new);
		}
	}
	else
	{
		if ((*root)->right != NULL)
		{
			new = heap_insert(&((*root)->right), value);
			heap_parent_vs_child(&((*root)->right), root);
			return (new);
		}
		else
		{
			new = binary_tree_node(*root, value);
			(*root)->right = new;
			heap_parent_vs_child(&((*root)->right), root);
			return (new);
		}
	}
	return (NULL);
}
