#include "main.h"

/**
 * _readline - readline
 *@prompt: prompt string
 * Return: allocated string or NULL
 */
char *_readline(const char *prompt)
{
	char *line;
	int	result;

	if (prompt != NULL)
		_puts(prompt);
	result = _getline(STDIN_FILENO, &line);
	if (result <= 0)
		return (NULL);
	return (line);
}
