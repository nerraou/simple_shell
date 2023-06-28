#include "list.h"

/**
 * list_remove_at - remove node at index
 * @list: linked list
 * @index: index to remove
 * @del: del function
*/
void list_remove_at(list_t *list, size_t index, void (*del)())
{
	node_t *prev;
	node_t *it;
	size_t i;

	prev = NULL;
	i = 0;
	it = list->head;
	while (it != NULL && i <= index)
	{
		if (i == index)
		{
			if (i == 0)
				list->head = it->next;
			else
				prev->next = it->next;
			if (i == list->size - 1)
				list->tail = prev;
			del(it->data);
			free(it);
			list->size--;
			break;
		}
		prev = it;
		it = it->next;
		i++;
	}
}
