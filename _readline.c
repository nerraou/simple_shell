#include "main.h"

/**
 * _readline - readline
 *@prompt: prompt string
 *@fd: file handle
 * Return: allocated string or NULL
 */
char *_readline(const char *prompt, int fd)
{
	char *line;
	int	result;

	if (prompt != NULL)
		_puts(prompt);
	result = _getline(fd, &line);
	if (result <= 0)
		return (NULL);
	return (line);
}
