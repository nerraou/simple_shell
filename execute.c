#include "main.h"

/**
 * execute - execute simple command
 *@shell: shell data
 *@argv: command arguments
 *@env: env variables
 * Return: 0 on success or -1 on failure
 */
int execute(shell_t *shell, char **argv, char **env)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		execve(argv[0], argv, env);
		exit(1);
	}
	wait(&status);
	if (WIFEXITED(status))
		shell->last_exit_code = WEXITSTATUS(status);
	return (0);
}
