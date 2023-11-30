#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure
 *	the height of.
 * Return: The calculated height, or 0 if `tree` is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);

	if (tree->right)
		r = 1 + binary_tree_height(tree->right);

	if (tree->left)
		l = 1 + binary_tree_height(tree->left);

	return ((r > l) ? r : l);
}
