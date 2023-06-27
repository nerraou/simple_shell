#include "lib.h"

/**
 * join_and_free - join and free s1
 * @s1: string
 * @s2: string
 * Return: allocated string
*/
char *join_and_free(char *s1, const char *s2)
{
	char *to_free;
	char *new_str;

	to_free = s1;
	new_str = strjoin(s1, s2);
	free(to_free);
	return (new_str);
}

/**
 * _getline - read next line from fd
 * @fd: file handle
 * @linep: line pointer
 * Return: -1: on error, 0: when eof reached, 1: on success
*/
int _getline(int fd, char **linep)
{
	static char buffer[BUFFER_SIZE + 1] = {0};
	ssize_t nl_index;
	ssize_t read_bytes;
	char *line;

	nl_index = _str_index_of(buffer, '\n');
	if (nl_index != -1)
	{
		buffer[nl_index] = '\0';
		*linep = _strdup(buffer);
		_strcpy(buffer, buffer + nl_index + 1);
		return (1);
	}
	line = _strdup(buffer);
	buffer[0] = '\0';
	while (1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(line);
			return (read_bytes);
		}
		buffer[read_bytes] = '\0';
		if (read_bytes > 0)
		{
			nl_index = _str_index_of(buffer, '\n');
			if (nl_index != -1)
				buffer[nl_index] = '\0';
			line = join_and_free(line, buffer);
			if (nl_index != -1)
			{
				_strcpy(buffer, buffer + nl_index + 1);
				*linep = line;
				return (1);
			}
		}
	}
	return (0);
}
