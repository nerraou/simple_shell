#include "parser.h"

/**
 * parse_line - parse command line
 * @line: command line string
 * Return: list of tokens or NULL
*/
list_t *parse_line(const char *line)
{
	return (tokenize(line));
}
