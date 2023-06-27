#include "list.h"

/**
 * node_new - create new node
 * @data: node data
 * Return: new allocated node or NULL
 */
node_t *node_new(void *data)
{
	node_t *node;

	node = malloc(sizeof(node_t));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}
