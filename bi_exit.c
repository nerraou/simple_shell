#include "main.h"

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
		exit_code = _atoi(av[1]);
	else
		exit_code = shell->last_exit_code;
	list_del(shell->envs, env_del);
	list_del(tokens, token_del);
	free(av);
	free_grid(env);
	exit(exit_code & 255);
	return (0);
}
