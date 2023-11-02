#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree, or 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (tree == NULL)
		return (h_left);
	if (tree->left != NULL)
		h_left += 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		h_right += 1 + binary_tree_height(tree->right);
	if (h_left >= h_right)
		return (h_left);
	else
		return (h_right);
}
