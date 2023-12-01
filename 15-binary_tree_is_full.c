#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full or not.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if tree is full, or 0 otherwise.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->right) &&
			bianry_tree_is_full(tree->left));

	return (0);
}
