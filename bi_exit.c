#include "main.h"

/**
 * bi_exit - builtin exit
 * @ac: arguments count
 * @av: arguments value
 * @shell: shell data
 * Return: 0: on success: 1: on failure
*/
int bi_exit(int ac, char **av, const shell_t *shell)
{
	if (ac > 2)
	{
		_puts_fd("./shell: exit: too many arguments\n", 2);
		return (1);
	}
	if (ac == 2)
		exit(_atoi(av[1]));
	exit(shell->last_exit_code);
	return (0);
}
