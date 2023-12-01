#include "binary_trees.h"

int helper(const binary_tree_t *tree, size_t i, size_t size);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node ot the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = binary_tree_size(tree);

	return (helper(tree, 0, size));
}

/**
 * helper - Helps `binary_tree_is_complete` function.
 * @tree: A pointer to the root node of the tree to check.
 * @i: The index of the node to check.
 * @size: The number of nodes in the tree.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int helper(const binary_tree_t *tree, size_t i, size_t size)
{
	if (!tree)
		return (1);

	if (i > size - 1)
		return (0);

	return (helper(tree->left, 2 * i + 1, size) &&
		helper(tree->right, 2 * i + 2, size));
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure
 *	 the size of.
 * Return: The calculated size, or 0 if `tree` is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->right) + binary_tree_size(tree->left));
}
