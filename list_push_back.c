#include "list.h"

/**
 * list_push_back - adds a new element at the end of the list
 * @list: linked list
 * @data: node data
 * Return: true on success, false on failure
 */
bool list_push_back(list_t *list, void *data)
{
	node_t *node;

	node = node_new(data);
	if (node == NULL)
		return (false);
	if (list->size == 0)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	list->size++;
	return (true);
}
