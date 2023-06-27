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
