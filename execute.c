#include "main.h"

/**
 * execute_builtin - execute simple command
 *@shell: shell data
 *@argc: command arguments count
 *@argv: command arguments value
 * Return: 0 on success or -1 on failure
 */
bool execute_builtin(shell_t *shell, int argc, char **argv)
{
	builtin_t builtins[BUILTINS_COUNT] = {
		{"exit", bi_exit},
		/* {"cd", bi_cd}, */
	};
	int i;

	for (i = 0; i < 1; i++)
	{
		if (_strcmp(argv[0], builtins[i].name) == 0)
			break;
	}
	if (i == BUILTINS_COUNT)
		return (false);
	shell->last_exit_code = builtins[i].action(argc, argv, shell);
	return (true);
}


/**
 * execute - execute simple command
 *@shell: shell data
 *@argc: command arguments count
 *@argv: command arguments value
 *@env: env variables
 * Return: 0 on success or -1 on failure
 */
int execute(shell_t *shell, int argc, char **argv, char **env)
{
	pid_t pid;

	if (execute_builtin(shell, argc, argv))
		return (0);
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
