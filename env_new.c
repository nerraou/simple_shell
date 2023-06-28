#include "main.h"

/**
 * env_new - create env entry
 * @key: env key
 * @value: env value
 * Return: allocated env entry or NULL
*/
env_t *env_new(const char *key, const char *value)
{
	env_t *env;

	env = malloc(sizeof(env_t));
	if (env == NULL)
		return (NULL);
	env->key = _strdup(key);
	env->value = _strdup(value);
	if (env->key == NULL || env->value == NULL)
	{
		free(env->key);
		free(env->value);
		free(env);
		return (NULL);
	}
	return (env);
}
