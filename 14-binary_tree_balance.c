#include "binary_trees.h"

/**
 * node_levels - counts the height of the node, but counting also the node in
 * the height
 * @tree: a pointer to a binary tree
 *
 * Return: the levels of a node, or 0 if the tree is NULL
 */
size_t node_levels(const binary_tree_t *tree)
{
	size_t levels = 0, l_left = 0, l_right = 0;

	if (tree == NULL)
		return (levels);
	levels++;
	if (tree->left != NULL)
		l_left += node_levels(tree->left);
	if (tree->right != NULL)
		l_right = node_levels(tree->right);
	if (l_left >= l_right)
		return (levels + l_left);
	else
		return (levels + l_right);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor, or 0 if the tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int hleft, hright;

	if (tree == NULL)
		return (0);
	hleft = (int)node_levels(tree->left);
	hright = (int)node_levels(tree->right);
	return (hleft - hright);
}
