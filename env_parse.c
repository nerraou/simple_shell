#include "main.h"

/**
 * env_parse - parse key=value env format
 * @str: env string
 * Return: new allocated env_t or NULL
*/
env_t *env_parse(const char *str)
{
	env_t *env;
	int	 equal_index;

	env = malloc(sizeof(env_t));
	if (env == NULL)
		return (NULL);
	equal_index = _str_index_of(str, '=');
	env->key = _substr(str, 0, equal_index);
	env->value = _strdup(str + equal_index + 1);
	if (env->key == NULL || env->value == NULL)
	{
		free(env->key);
		free(env->value);
		free(env);
		return (NULL);
	}
	return (env);
}
