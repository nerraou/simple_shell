#include "main.h"

/**
 * eval -  evaluate commands input
 * @shell: shell data
 * @filename: filename
*/
void eval(shell_t *shell, const char *filename)
{
	char *line;
	char *prompt_string;
	list_t *commands;
	int fd;

	fd = STDIN_FILENO;
	if (filename != NULL)
		fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror(shell->program_name);
		return;
	}
	if (isatty(fd))
		prompt_string = "$> ";
	else
		prompt_string = NULL;
	while (1)
	{
		line = _readline(prompt_string, fd);
		if (line == NULL)
			break;
		commands = parse_line(line, shell->program_name);
		free(line);
		if (commands != NULL)
		{
			execute_list(shell, commands);
			list_del(commands, token_del);
		}
	}
}
