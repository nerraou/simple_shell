#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

/**
 * struct node_s - reperesent a node
 * @data: data
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct node_s
{
	void *data;
	struct node_s *next;
} node_t;


/**
 * struct list_s - singly linked list
 * @head: the first element in the list
 * @tail: the last element in the list
 * @size: elements count
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	node_t *head;
	node_t *tail;
	size_t size;
} list_t;

list_t *list_new(void);
node_t *node_new(void *data);
bool list_push_back(list_t *list, void *data);
void list_clear(list_t *list, void (*del)());
void list_del(list_t *list, void (*del)());
void list_remove_at(list_t *list, size_t index, void (*del)());

#endif /* LIST_H */
