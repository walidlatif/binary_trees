#include "binary_trees.h"

/**
 * binary_tree_is_node - checks if a node is a node
 * @node: a pointer to the node to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_node(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left != NULL || node->right != NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_hastwoleafs - checks if the node has two leafs
 * @node: a pointer to the node to check
 *
 * Return: -1 if the node doesn't have two leafs, 0 if it isn'a a node
 * and 1 if has two leafs
 */
int binary_tree_hastwoleafs(const binary_tree_t *node)
{
	if (binary_tree_is_node(node))
	{
		if (node->left != NULL && node->right != NULL)
			return (1);
		return (-1);
	}
	return (0);
}

/**
 * if_treeisfull_preorder - uses pre-order traversal to verify the fullness
 * of the tree. If the function returns -1, stops the traversal.
 * @tree: a pointer to the root node of the tree to traverse
 *
 * Return: 0 if the tree is NULL, -1 the requested statements are false, and
 * 1 if the traversal ended succesfully.
 */
int if_treeisfull_preorder(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if (binary_tree_hastwoleafs(tree) == -1)
			return (-1);
		if (if_treeisfull_preorder(tree->left) == -1)
			return (-1);
		if (if_treeisfull_preorder(tree->right) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int isfull = if_treeisfull_preorder(tree);

	if (isfull == -1)
		return (0);
	if (isfull == 0)
		return (0);
	return (1);
}
