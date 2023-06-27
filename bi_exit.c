#include "main.h"

/**
 * is_int - check if str contains integer
 * @str: string
 * Return: true if str is integer, otherwise false
*/
bool is_int(const char *str)
{
	int i;

	i = 0;
	while (_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break;
		i++;
	}
	while (_isspace(str[i]))
		i++;
	if (str[i] != '\0')
		return (false);
	return (true);
}

/**
 * bi_exit - builtin exit
 * @ac: arguments count
 * @av: arguments value
 * @env: envs
 * @shell: shell data
 * @tokens: tokens list
 * Return: 0: on success: 1: on failure
*/
int bi_exit(int ac, char **av, char **env, shell_t *shell, list_t *tokens)
{
	int exit_code;

	if (ac > 2)
	{
		_puts_fd("./shell: exit: too many arguments\n", 2);
		return (1);
	}
	if (ac == 2)
	{
		if (is_int(av[1]) == false)
		{
			_puts_fd("./shell: exit: ", 2);
			_puts_fd(av[1], 2);
			_puts_fd(": numeric argument required\n", 2);
			exit_code = 2;
		}
		else
			exit_code = _atoi(av[1]);
	}
	else
		exit_code = shell->last_exit_code;
	list_del(shell->envs, env_del);
	list_del(tokens, token_del);
	free(av);
	free_grid(env);
	exit(exit_code);
	return (0);
}
