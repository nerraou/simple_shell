#include "main.h"

/**
 * is_varname - check if variable name valid
 * @str: variable name
 * Return: true or false
*/
bool is_varname(const char *str)
{
	int	i;

	if (!_isalpha(str[0]) && str[0] != '_')
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (!_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

/**
 * bi_setenv - set env
 * @ac: arguments count
 * @av: arguments value
 * @env: envs
 * @shell: shell data
 * Return: 0: on success: 1: on failure
*/
int bi_setenv(int ac, char **av, char **env, shell_t *shell)
{
	node_t *it;
	env_t *env_entry;
	char *value;
	(void)env;

	if (ac != 3)
	{
		_puts_fd("./shell: setenv: usage: setenv VARIABLE VALUE\n", 2);
		return (1);
	}
	if (is_varname(av[1]) == false)
	{
		_puts_fd("./shell: setenv: invalid variable name\n", 2);
		return (1);
	}
	it = shell->envs->head;
	while (it != NULL)
	{
		env_entry = it->data;
		if (_strcmp(env_entry->key, av[1]) == 0)
		{
			value = _strdup(av[2]);
			if (value == NULL)
				return (1);
			free(env_entry->value);
			env_entry->value = value;
			return (0);
		}
		it = it->next;
	}
	env_entry = env_new(av[1], av[2]);
	if (env_entry == NULL)
		return (1);
	if (list_push_back(shell->envs, env_entry) == false)
	{
		free(env_entry);
		return (1);
	}
	return (0);
}
