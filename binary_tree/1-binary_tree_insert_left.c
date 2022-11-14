#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts node as the
 * left-child of another node
 * @parent: binary_tree_t node
 * @value: int variable
 * Return: new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *temp;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
		return (NULL);

	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	new->n = value;

	if (parent->left == NULL)
	{
		parent->left = new;
		return (new);
	}
	temp = parent->left;
	parent->left = new;
	new->left = temp;
	temp->parent = new;

	return (new);
}
