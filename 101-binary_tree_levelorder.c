#include "binary_trees.h"

void postorder_with_level(const binary_tree_t *tree,
			  void (*func)(int),
			  size_t level);

/**
 * binary_tree_levelorder - Goes through a binary tree using
 *	level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxLevel;

	if (!tree || !func)
		return;

	maxLevel = binary_tree_height(tree) + 1;

	for (level = 1; level < maxLevel + 1; level++)
		postorder_with_level(tree, func, level);
}

/**
 * postorder_with_level - Goes through a binary tree using post-order traverse
 *	with level.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 * @level: The level of the tree to call `func` for.
 */
void postorder_with_level(const binary_tree_t *tree, void (*func)(int),
		size_t level)
{
	if (level == 1)
	{
		func(tree->n);
	}
	else
	{
		postorder_with_level(tree->left, func, level - 1);
		postorder_with_level(tree->right, func, level - 1);
	}
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
