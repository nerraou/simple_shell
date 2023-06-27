#include "lib.h"

/**
 * _isspace - check if a given character is whitespace
 * @c: character
 * Return: true: if space, false: if not
*/
bool _isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (true);
	if (c == '\r' || c == '\t' || c == '\v')
		return (true);
	return (false);
}
