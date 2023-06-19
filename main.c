#include "main.h"
#include "lib.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
	char *line;
	ssize_t result;
	size_t size;
	pid_t pid;

	while (1)
	{
		line = NULL;
		result = getline(&line, &size, stdin);
		// remove trailing newline if existed
		_puts("command to be executed");
		_puts(line);
		_puts("\n");
		free(line);
	}

	return 0;
}
