#include "main.h"

/**
 * shell_init - init shell data
 * @shell: shell data
 * @env: initial envs
 * Return: 0: success, -1: failure
*/
int shell_init(shell_t *shell, char *env[])
{
	shell->last_command_status = 0;
	shell->envs = env_init(env);
	if (shell->envs == NULL)
		return (-1);
	return (0);
}
