#include "parser.h"

/**
 * token_new - create new token
 * @value: token value
 * @type: token type
 * Return: allocated token_t*
*/
token_t *token_new(char *value, token_type_t type)
{
	token_t *token;

	token = malloc(sizeof(token_t));
	if (token == NULL)
		return (NULL);
	token->value = value;
	token->type = type;
	return (token);
}
