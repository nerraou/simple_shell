#include "lib.h"

/**
 * _strdup - duplicate an array
 * @str: string
 *Return: new copy of str
 */
char *_strdup(const char *str)
{
	size_t len;
	size_t i;
	char *dest;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
	{
		dest[i] = str[i];
	}
	dest[i] = '\0';
	return (dest);
}
