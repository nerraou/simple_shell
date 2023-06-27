#include "parser.h"

/**
 * token_del - delete token
 * @token: token
 */
void token_del(token_t *token)
{
	if (token == NULL)
		return;
	free(token->value);
	free(token);
}
