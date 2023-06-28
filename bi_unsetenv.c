#include "main.h"

/**
 * bi_unsetenv - unset env
 * @ac: arguments count
 * @av: arguments value
 * @env: envs
 * @shell: shell data
 * Return: 0: on success: 1: on failure
*/
int bi_unsetenv(int ac, char **av, char **env, shell_t *shell)
{
	node_t *it;
	env_t *env_entry;
	size_t i;
	(void)env;

	if (ac != 2)
	{
		_puts_fd("./shell: unsetenv: usage: unsetenv VARIABLE\n", 2);
		return (1);
	}
	i = 0;
	it = shell->envs->head;
	while (it != NULL)
	{
		env_entry = it->data;
		if (_strcmp(av[1], env_entry->key) == 0)
		{
			list_remove_at(shell->envs, i, env_del);
			break;
		}
		it = it->next;
		i++;
	}
	return (0);
}
