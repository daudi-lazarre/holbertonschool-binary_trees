#include "binary_trees.h"
#include <stdio.h> 
/**
* binary_tree_levelorder - goes through a binary tree using level-order traversal
* @tree: a pointer to the root node of the tree to measure the height.
* @func: a pointer to a function to call for each node. The value in the node must be passed as a
* parameter to this function.
* Return: the height of a binary tree or 0 if tree is NULL
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	size_t lvl = depth_root(tree);
	printf ("lvl: %li\n", lvl);
	func(tree->n);

	while (binary_tree_depth(tree) == lvl)
		{
		binary_tree_levelorder(tree->left, func);
		binary_tree_levelorder(tree->right, func);
		lvl++;
		}
	
}

size_t depth_root(const binary_tree_t *tree)
{
	size_t depth_r = 0;
	if (tree->parent == NULL)
		{
		depth_r = binary_tree_depth(tree);
		}
	return (depth_r);
}
/**
* binary_tree_height - measures the height of a binary tree
* @tree: a pointer to the root node of the tree to measure the height.
* Return: the height of a binary tree or 0 if tree is NULL
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	height_l = binary_tree_height(tree->left) + 1;
	height_r = binary_tree_height(tree->right) + 1;

	if (height_l >= height_r)
		return (height_l);

	else
		return (height_r);
}

/**
* binary_tree_depth - measures the depth of a binary tree
* @tree: a pointer to the root node of the tree to measure the height.
* Return: the depth of a binary tree or 0 if tree is NULL
*/

size_t binary_tree_depth(const binary_tree_t *tree)

{

	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}



