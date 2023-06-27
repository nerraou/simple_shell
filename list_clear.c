#include "list.h"

/**
 * list_clear - delete all nodes in the list
 * @list: list
 * @del: free node.data function
 */
void list_clear(list_t *list, void (*del)())
{
	node_t *it;
	node_t *to_del;

	if (list == NULL)
		return;
	it = list->head;
	while (it != NULL)
	{
		to_del = it;
		it = it->next;
		del(to_del->data);
		free(to_del);
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
}
