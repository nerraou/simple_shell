#include "main.h"

/**
 * _readline - readline
 *@prompt: prompt string
 * Return: allocated string or NULL
 */
char *_readline(const char *prompt)
{
	char	*line;
	ssize_t	result;
	size_t	size;

	_puts(prompt);
	line = NULL;
	result = getline(&line, &size, stdin);
	if (result == -1)
		return (NULL);
	if (line[result - 1] == '\n')
		line[result - 1] = '\0';
	return (line);
}
