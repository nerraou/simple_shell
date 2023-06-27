#include "main.h"

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

	if (access(argv[0], F_OK | X_OK) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		execve(argv[0], argv, env);
		exit(1);
	}
	wait(&shell->last_command_status);
	if (WIFEXITED(shell->last_command_status))
		shell->last_exit_code = WEXITSTATUS(shell->last_command_status);
	return (0);
}
