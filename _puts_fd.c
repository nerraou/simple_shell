#include "lib.h"

/**
 * _puts_fd - print string to fd
 *@str: string
 *@fd: file descriptor
 */
void _puts_fd(const char *str, int fd)
{
	write(fd, str, _strlen(str));
}
