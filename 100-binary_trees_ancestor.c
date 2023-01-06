#include "binary_trees.h"

/**
* binary_trees_ancestor - finds the lowest common ancestor of two nodes
* @first: a pointer to the first node
* @second: a pointer to the second node
* Return: a pointer to the  lowest common ancestor
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)

{
	int depth_1 = binary_tree_depth(first);
	int depth_2 = binary_tree_depth(second);

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	if (depth_1 > depth_2)
		return (binary_trees_ancestor(first->parent, second));
	else
		return (binary_trees_ancestor(first, second->parent));

	return (binary_trees_ancestor(first->parent, second->parent));

}


/**
* binary_tree_depth - measures the depth of a binary tree
* @tree: a pointer to the root node of the tree to measure the depth.
* Return: the depth of a binary tree or 0 if tree is NULL
*/

size_t binary_tree_depth(const binary_tree_t *tree)

{

	if (tree == NULL || tree->parent == NULL)
		return (0);

	return (binary_tree_depth(tree->parent) + 1);
}
