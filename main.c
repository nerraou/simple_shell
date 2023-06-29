#include "main.h"

/**
 * main - check the code
 * @ac: arguments count
 * @av: arguments value
 * @env: env variables
 * Return: Always 0.
 */
int main(int ac, char *av[], char *env[])
{
	shell_t shell;

	if (ac > 2)
	{
		_puts_fd(av[0], 2);
		_puts_fd(": usage: ./hsh [filename]\n", 2);
		exit(1);
	}
	if (shell_init(&shell, env, av[0]) == -1)
		exit(1);
	eval(&shell, av[1]);
	list_del(shell.envs, env_del);
	return (0);
}
