#include "main.h"

/**
 * env_init - init envs list
 * @env_arr: key=value env array
 * Return: linked list of env_t* or NULL
*/
list_t	*env_init(char *env_arr[])
{
	list_t *env_list;
	env_t *env;
	int		i;

	env_list = list_new();
	if (env_list == NULL)
		return (NULL);
	for (i = 0; env_arr[i] != NULL; i++)
	{
		env = env_parse(env_arr[i]);
		if (env == NULL)
		{
			list_del(env_list, env_del);
			return (NULL);
		}
		list_push_back(env_list, env);
	}
	return (env_list);
}
