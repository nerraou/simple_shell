#include "main.h"

/**
 * _setenv - set env
 * @envs: envs list
 * @name: variable name
 * @value: variable value
 * Return: env entry or NULL
*/
int _setenv(list_t *envs, const char *name, const char *value)
{
	env_t *env_entry;
	char *value_dup;

	env_entry = _getenv(envs, name);
	if (env_entry)
	{
		value_dup = _strdup(value);
		if (value == NULL)
			return (1);
		free(env_entry->value);
		env_entry->value = value_dup;
		return (0);
	}
	env_entry = env_new(name, value);
	if (env_entry == NULL)
		return (1);
	if (list_push_back(envs, env_entry) == false)
	{
		free(env_entry);
		return (1);
	}
	return (0);
}
