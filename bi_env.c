#include "main.h"

/**
 * bi_env - print envs
 * @ac: arguments count
 * @av: arguments value
 * @env: envs
 * Return: 0: on success: 1: on failure
*/
int bi_env(int ac, char **av, char **env)
{
	int i;
	(void)ac;
	(void)av;

	for (i = 0; env[i] != NULL; i++)
	{
		_puts(env[i]);
		_puts("\n");
	}
	return (0);
}
