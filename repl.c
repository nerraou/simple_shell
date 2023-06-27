#include "main.h"

/**
 * repl -  read eval print loop
 * @shell: shell data
*/
void repl(shell_t *shell)
{
	char *line;
	list_t *commands;

	(void)commands;
	(void)shell;

	while (1)
	{
		line = _readline("$> ");
		if (line == NULL)
			break;
		commands = parse_line(line);
		execute_list(shell, commands);
		list_del(commands, token_del);
	}
}
