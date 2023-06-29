#include "main.h"

/**
 * shell_init - init shell data
 * @shell: shell data
 * @env: initial envs
 * @program_name: program name
 * Return: 0: success, -1: failure
*/
int shell_init(shell_t *shell, char *env[], char *program_name)
{
	shell->program_name = program_name;
	shell->last_command_status = 0;
	shell->last_exit_code = 0;
	shell->envs = env_init(env);
	if (shell->envs == NULL)
		return (-1);
	return (0);
}
