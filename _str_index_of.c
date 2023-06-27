#include "lib.h"

/**
 * _str_index_of - get index of c
 * @str: haystack
 * @c: needle
 * Return: index of c or -1
*/
ssize_t _str_index_of(const char *str, char c)
{
	ssize_t i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}
