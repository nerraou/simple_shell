#include "lib.h"

/**
 * _isalnum - check if c is alphanumeric
 * @c: character
 * Return: true or false
*/
bool _isalnum(char c)
{
	return (_isdigit(c) || _isalpha(c));
}
