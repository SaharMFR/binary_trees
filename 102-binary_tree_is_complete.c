#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node ot the tree to check.
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *l, *r;

	if (!tree)
		return (0);

	l = tree->left;
	r = tree->right;

	if (binary_tree_is_leaf(tree))
		return (1);

	if (!l && r)
		return (0);

	if (binary_tree_height(l) == binary_tree_height(r)
			|| binary_tree_height(l) == binary_tree_height(r) - 1)
	{
		if (binary_tree_is_complete(l) && binary_tree_is_complete(r))
			return (1);
	}

	return (0);
}

/**
 * binary_tree_is_leaf - Checks if a node is a leaf or not.
 * @node: A pointer to the node to check.
 * Return: 1 if `node` is a leaf, 0 otherwise.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node || node->right || node->left)
		return (0);
	return (1);
}

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
