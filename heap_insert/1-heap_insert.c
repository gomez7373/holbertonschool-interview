#include "binary_trees.h"

/**
 * swap_values - Swaps values between two heap nodes
 * @a: first node
 * @b: second node
 */
void swap_values(heap_t *a, heap_t *b)
{
	int temp = a->n;

	a->n = b->n;
	b->n = temp;
}

/**
 * heapify_up - Reorders heap after insertion to maintain max heap
 * @node: pointer to the node to heapify up
 * Return: final position of the node after swap(s)
 */
heap_t *heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_values(node, node->parent);
		node = node->parent;
	}
	return (node);
}

/**
 * get_insert_parent - Finds first available parent for insertion (level-order)
 * @root: pointer to root of the heap
 * Return: pointer to the parent where to insert the new node
 */
heap_t *get_insert_parent(heap_t *root)
{
	heap_t **queue;
	int front = 0, rear = 0;
	heap_t *current;

	queue = malloc(sizeof(heap_t *) * 1024);
	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		current = queue[front++];

		if (!current->left || !current->right)
		{
			free(queue);
			return (current);
		}

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	free(queue);
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the heap
 * @value: value to insert
 * Return: pointer to the inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *new_node;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = get_insert_parent(*root);
	if (!parent)
		return (NULL);

	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;

	return (heapify_up(new_node));
}
