#include "lib.h"

/**
 * word_count - get words count
 *@s: string
 *@c: delimiter
 *Return: string length
 */
int word_count(const char *s, char c)
{
	int index;
	int word;

	word = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		if (s[index])
			word++;
		while (s[index] && s[index] != c)
			index++;
	}
	return (word);
}

/**
 * free_2d - free 2d array
 * @grid: 2d array
 * @height: height
 */
void free_2d(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}

/**
 * strtow - split string to words
 * @str: string
 * @c: delimiter
 *Return: return 2d array
 */
char **strtow(const char *str, char c)
{
	char **array;
	int i;
	int words;
	int start;
	int length;

	if (!str || str[0] == '\0')
		return (NULL);
	words = word_count(str, c);
	if (words == 0)
		return (NULL);
	i = 0;
	start = 0;
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	while (i < words)
	{
		while (str[start] == c && str[start])
			start++;
		length = _strclen(str + start, c);
		array[i] = _substr(str, start, length);
		if (!array[i])
		{
			free_2d(array, i);
			return (NULL);
		}
		start += length;
		i++;
	}
	array[i] = NULL;
	return (array);
}
