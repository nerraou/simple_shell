#include "parser.h"

/**
 * expect - check if token expects next token
 * @token: token
 * @next: next token
 * Return: true: if token expects next, otherwise false
*/
bool expect(const token_t *token, const token_t *next)
{
	if (token->type == T_SEMICOLON && (next != NULL && next->type != T_WORD))
		return (false);
	if (token->type == T_OR && (next == NULL || next->type != T_WORD))
		return (false);
	if (token->type == T_AND && (next == NULL || next->type != T_WORD))
		return (false);
	return (true);
}

/**
 * parse_line - parse command line
 * @line: command line string
 * @program_name: program name
 * Return: list of tokens or NULL
*/
list_t *parse_line(const char *line, const char *program_name)
{
	list_t *tokens;
	node_t *it;
	token_t *current_token;
	token_t *next_token;

	tokens = tokenize(line);
	if (tokens == NULL)
		return (NULL);
	it = tokens->head;
	if (it != NULL)
	{
		current_token = it->data;
		if (is_token_seperator(current_token->type))
		{
			_puts_fd(program_name, 2);
			_puts_fd(": unexpected token\n", 2);
			list_del(tokens, token_del);
			return (NULL);
		}
	}
	while (it != NULL)
	{
		current_token = it->data;
		next_token = NULL;
		if (it->next)
			next_token = it->next->data;
		if (expect(current_token, next_token) == false)
		{
			_puts_fd(program_name, 2);
			_puts_fd(": unexpected token\n", 2);
			list_del(tokens, token_del);
			return (NULL);
		}
		it = it->next;
	}
	return (tokens);
}
