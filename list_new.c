#include "list.h"

/**
 * list_new - create new list
 * Return: new allocated list or NULL
 */
list_t *list_new(void)
{
	list_t *list;

	list = malloc(sizeof(list_t));
	if (list == NULL)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}
