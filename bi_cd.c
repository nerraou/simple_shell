#include "main.h"

/**
 * update_envs - update pwd and oldpwd envs
 * @env: envs list
 * Return: 0: on success: -1: on failure
*/
int	update_envs(list_t *env)
{
	env_t *env_entry;
	char *cwd;

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
		return (-1);
	env_entry = _getenv(env, "PWD");
	if (env_entry)
	{
		_setenv(env, "OLDPWD", env_entry->value);
		free(env_entry->value);
		env_entry->value = cwd;
	}
	else
	{
		_setenv(env, "PWD", cwd);
		_setenv(env, "OLDPWD", cwd);
		free(cwd);
	}
	return (0);
}

/**
 * get_path - get path
 * @ac: arguments count
 * @av: arguments value
 * @envs: envs list
 * Return: path or NULL
*/
char *get_path(int ac, char **av, const list_t *envs)
{
	env_t *env_entry;
	char *path;

	if (ac == 1)
	{
		env_entry = _getenv(envs, "HOME");
		if (env_entry == NULL)
		{
			_puts_fd("./shell: cd: HOME not set\n", 2);
			return (NULL);
		}
		path = env_entry->value;
		return (path);
	}
	path = av[1];
	if (_strcmp(path, "-") == 0)
	{
		env_entry = _getenv(envs, "OLDPWD");
		if (env_entry == NULL)
		{
			_puts_fd("./shell: cd: OLDPWD not set\n", 2);
			return (NULL);
		}
		path = env_entry->value;
	}
	return (path);
}

/**
 * bi_cd - change directory
 * @ac: arguments count
 * @av: arguments value
 * @env: envs
 * @shell: shell data
 * Return: 0: on success: 1: on failure
*/
int bi_cd(int ac, char **av, char **env, shell_t *shell)
{
	char *path;
	(void)env;

	if (ac > 2)
	{
		_puts_fd("./shell: cd: usage: cd DIRECTORY\n", 2);
		return (1);
	}
	path = get_path(ac, av, shell->envs);
	if (path == NULL)
		return (1);
	if (chdir(path) == -1)
	{
		perror("./shell: cd");
		return (1);
	}
	if (update_envs(shell->envs) == -1)
	{
		_puts_fd("./shell: cd: error\n", 2);
		return (1);
	}
	return (0);
}
