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
	return (_setenv(shell->envs, av[1], av[2]));
}
