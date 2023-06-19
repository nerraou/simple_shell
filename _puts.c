#include "lib.h"

/**
 * _puts - print string
 *@str: string
 */
void _puts(const char *str)
{
	write(1, str, _strlen(str));
}
