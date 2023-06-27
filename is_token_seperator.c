#include "main.h"

/**
 * is_token_seperator - check if token is a command seperator
 * @type: token type to check
 * Return: true or false
*/
bool is_token_seperator(token_type_t type)
{
	return (type == T_AND || type == T_OR || type == T_SEMICOLON);
}
