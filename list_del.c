#include "list.h"

/**
 * list_del - delete all nodes in the list
 * @list: list
 * @del: free node.data function
 */
void list_del(list_t *list, void (*del)())
{
	list_clear(list, del);
	free(list);
}
