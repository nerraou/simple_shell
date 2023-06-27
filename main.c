#include "main.h"

/**
 * main - check the code
 * @ac: arguments count
 * @av: arguments value
 * @env: env variables
 * Return: Always 0.
 */
int main(int ac, char *av[], char *env[])
{
	shell_t shell;
	(void)ac;
	(void)av;

	if (shell_init(&shell, env) == -1)
		exit(1);
	repl(&shell);
	/* clear env list */
	return (0);
}
