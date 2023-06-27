#include "main.h"

/**
 * _getenv - get env by name
 * @envs: envs list
 * @name: variable name
 * Return: env value or NULL
*/
char *_getenv(const list_t *envs, const char *name)
{
	node_t *it;
	env_t *env_entry;

	it = envs->head;
	while (it != NULL)
	{
		env_entry = it->data;
		if (_strcmp(env_entry->key, name) == 0)
			return (env_entry->value);
		it = it->next;
	}
	return (NULL);
}
