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
 * _balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor, or 0 if the tree is NULL
 */
int _balance(const binary_tree_t *tree)
{
	int hleft, hright;

	if (tree == NULL)
		return (0);
	hleft = (int)node_levels(tree->left);
	hright = (int)node_levels(tree->right);
	return (hleft - hright);
}

/**
 * _hastwoleafs - checks if the node has two leafs
 * @node: a pointer to the node to check
 *
 * Return: -1 if the node doesn't have two leafs, 0 if it isn'a a node
 * and 1 if has two leafs
 */
int _hastwoleafs(const binary_tree_t *node)
{
	if (node != NULL && (node->left != NULL || node->right != NULL))
	{
		if (node->left != NULL && node->right != NULL)
			return (1);
		return (-1);
	}
	return (0);
}

/**
 * if_perfect_preorder - uses pre-order traversal to check if the tree
 * is perfect. If the function returns -1, stops the traversal
 * @tree: a pointer to the root node of the tree to traverse
 *
 * Return: 0 if the tree is NULL, -1 the requested statements are false, and
 * 1 if the traversal ended succesfully
 */
int if_perfect_preorder(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if (_hastwoleafs(tree) == -1 || _balance(tree) != 0)
			return (-1);
		if (if_perfect_preorder(tree->left) == -1)
			return (-1);
		if (if_perfect_preorder(tree->right) == -1)
			return (-1);
		return (1);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int isperfect = if_perfect_preorder(tree);

	if (isperfect == -1 || isperfect == 0)
		return (0);
	return (1);
}
