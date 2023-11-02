#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: the uncle node, or NULL if:
 *   - node is NULL
 *   - node has no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grandparent, *Parent;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);
	grandparent = node->parent->parent;
	Parent = node->parent;
	if (Parent == grandparent->left)
	{
		if (grandparent->right != NULL)
			return (grandparent->right);
	}
	if (Parent == grandparent->right)
	{
		if (grandparent->left != NULL)
			return (grandparent->left);
	}
	return (NULL);

}
