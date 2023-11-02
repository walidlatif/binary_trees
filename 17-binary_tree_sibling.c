#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: the sibling node, or NULL if:
 *   - the parent is NULL
 *   - node is NULL
 *   - node has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->left == node)
	{
		if (node->parent->right != NULL)
			return (node->parent->right);
	}
	if (node->parent->right == node)
	{
		if (node->parent->left != NULL)
			return (node->parent->left);
	}
	return (NULL);
}
