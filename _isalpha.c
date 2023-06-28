#include "lib.h"

/**
 * _isalpha - check if c is alpha
 * @c: character
 * Return: true or false
*/
bool _isalpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
