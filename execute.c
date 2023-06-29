#include "main.h"

/**
 * resolve_bin_path - resolve binary path
 * @shell: shell data
 * @bin: binary base path
 * Return: 0: on success, -1: on error
*/
int resolve_bin_path(const shell_t *shell, char **bin)
{
	env_t *path_env;
	char **paths;
	char *bin_path;
	int i;

	if (**bin == '.' || **bin == '/')
		return (access(*bin, F_OK | X_OK));
	path_env = _getenv(shell->envs, "PATH");
	if (path_env == NULL)
		return (access(*bin, F_OK | X_OK));
	paths = strtow(path_env->value, ':');
	if (paths == NULL)
		return (-1);
	for (i = 0; paths[i] != NULL; i++)
	{
		bin_path = strjoin(paths[i], "/");
		if (bin_path == NULL)
			break;
		bin_path = join_and_free(bin_path, *bin);
		if (bin_path == NULL)
			break;
		if (access(bin_path, F_OK | X_OK) == 0)
		{
			free_grid(paths);
			free(*bin);
			*bin = bin_path;
			return (0);
		}
		free(bin_path);
	}
	free_grid(paths);
	return (-1);
}

/**
 * execute - execute simple command
 *@shell: shell data
 *@argv: command arguments value
 *@env: env variables
 * Return: 0 on success or -1 on failure
 */
int execute(shell_t *shell, char **argv, char **env)
{
	pid_t pid;

	if (resolve_bin_path(shell, argv) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		execve(argv[0], argv, env);
		perror(shell->program_name);
		exit(1);
	}
	wait(&shell->last_command_status);
	if (WIFEXITED(shell->last_command_status))
		shell->last_exit_code = WEXITSTATUS(shell->last_command_status);
	return (0);
}
