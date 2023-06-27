#ifndef PARSER_H
#define PARSER_H

#include "lib.h"
#include "list.h"

#define T_WORD 1
#define T_OR 2
#define T_AND 3
#define T_SEMICOLON 4

typedef int token_type_t;

/**
 * struct token_s - env variable
 * @value: token value
 * @type: token type
 *
 * Description: env entry
 */
typedef struct token_s
{
	char *value;
	token_type_t type;
} token_t;

typedef int (*recognizer_t)(list_t *tokens, const char *str);

token_t *token_new(char *value, token_type_t type);
void token_del(token_t *token);
list_t *tokenize(const char *str);
list_t *parse_line(const char *line);

#endif /* PARSER_H */
