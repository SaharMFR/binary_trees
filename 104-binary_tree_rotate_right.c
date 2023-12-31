#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (!tree || !tree->left)
		return (NULL);

	tree->left->parent = tree->parent;
	tree->parent = tree->left;
	tree->left = tree->parent->right;
	tree->parent->right = tree;

	return (tree->parent);
}
