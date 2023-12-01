#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree || !tree->right)
		return (NULL);

	tree->right->parent = tree->parent;
	tree->parent = tree->right;
	tree->right = tree->parent->left;
	tree->parent->left = tree;

	return (tree->parent);
}
