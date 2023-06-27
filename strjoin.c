#include "lib.h"

/**
 * strjoin - join two strings
 * @s1: string
 * @s2: string
 * Return: allocated string
*/
char *strjoin(const char *s1, const char *s2)
{
	char *str;
	size_t s1_len;
	size_t s2_len;

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	_strcpy(str, s1);
	_strcpy(str + s1_len, s2);
	return (str);
}
