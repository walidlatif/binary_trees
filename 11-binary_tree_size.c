#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 *
 * Return: the size of a binary tree, or 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t nnodes = 0;

	if (tree == NULL)
		return (nnodes);
	nnodes++;
	nnodes += binary_tree_size(tree->left) + binary_tree_size(tree->right);
	return (nnodes);
}
