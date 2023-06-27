#include "main.h"

/**
 * eval -  evaluate commands input
 * @shell: shell data
*/
void eval(shell_t *shell)
{
	char *line;
	char *prompt_string;
	list_t *commands;

	if (isatty(0))
		prompt_string = "$> ";
	else
		prompt_string = NULL;
	while (1)
	{
		line = _readline(prompt_string);
		if (line == NULL)
			break;
		commands = parse_line(line);
		execute_list(shell, commands);
		list_del(commands, token_del);
	}
}
