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
 * print_exit_error - print exit error
 * @arg: argument
 * @program_name: program name
*/
void print_exit_error(const char *arg, const char *program_name)
{
	_puts_fd(program_name, 2);
	_puts_fd(": exit: Illegal number: ", 2);
	_puts_fd(arg, 2);
	_puts_fd("\n", 2);
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
		_puts_fd(shell->program_name, 2);
		_puts_fd(": exit: too many arguments\n", 2);
		return (1);
	}
	if (ac == 2)
	{
		if (is_int(av[1]) == false)
		{
			print_exit_error(av[1], shell->program_name);
			return (2);
		}
		else
		{
			exit_code = _atoi(av[1]);
			if (exit_code < 0)
			{
				print_exit_error(av[1], shell->program_name);
				return (2);
			}
		}
	}
	else
		exit_code = shell->last_exit_code;
	list_del(shell->envs, env_del);
	list_del(tokens, token_del);
	free_grid(av);
	free_grid(env);
	exit(exit_code & 255);
	return (0);
}
