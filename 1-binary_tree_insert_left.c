#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child
 *	of another node.
 * @parent: A pointer to the node to insert the left_child in.
 * @value: The value to store in the new node.
 * Return: A pointer to the created node, or NULL on failure
 *	or if `parent` is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	if (!parent)
		return (NULL);

	node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->right = NULL;
	node->left = parent->left;
	parent->left = node;

	if (node->left)
		(node->left)->parent = node;

	return (node);
}
