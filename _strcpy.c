#include "lib.h"

/**
 * _strcpy - copy stc to dest
 *@src: source string
 *@dest: destination string
 *Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
