#include "lib.h"

/**
 * _strlen - string length
 *@str: string
 *Return: string length
 */

size_t _strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
