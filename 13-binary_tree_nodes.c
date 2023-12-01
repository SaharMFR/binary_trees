#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child
 *	in a binary tree.
 * @tree: A pointer to the root node of the tree to count the
 *	number of nodes.
 * Return: The calculated number of nodes, or 0 if `tree` is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	return (binary_tree_size(tree) - binary_tree_leaves(tree));
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

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count
 *	the number of leaves for.
 * Return: The calculated number of leaves, or 0 if `tree` is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}
