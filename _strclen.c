#include "lib.h"

/**
 * _strclen - string length
 *@str: string
 *@c: c
 *Return: string length
 */
size_t _strclen(const char *str, char c)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}
