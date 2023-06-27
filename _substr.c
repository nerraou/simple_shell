#include "lib.h"

/**
 * _substr - get sub string
 *@s: string
 *@start: start
 *@len: len
 *Return: sub string
 */
char *_substr(const char *s, int start, int len)
{
	char *str;
	int size;
	int i;

	size = 0;
	while (s[size] != '\0')
		size++;
	if (start > size)
		return (NULL);
	if (size < len)
		len = size;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}

	str[len] = '\0';
	return (str);
}
