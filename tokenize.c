#include "parser.h"

/**
 * recognize_or - recognize or(||) token
 * @tokens: list to push token to
 * @str: test subject
 * Return: -1: error, 2: success, 0: not recognizable
*/
int recognize_or(list_t *tokens, const char *str)
{
	token_t *token;

	if (str[0] == '|' && str[1] == '|')
	{
		token = token_new(NULL, T_OR);
		if (token == NULL || list_push_back(tokens, token) == 0)
		{
			token_del(token);
			return (-1);
		}
		return (2);
	}
	return (0);
}

/**
 * recognize_and - recognize and(&&) token
 * @tokens: list to push token to
 * @str: test subject
 * Return: -1: error, 2: success, 0: not recognizable
*/
int recognize_and(list_t *tokens, const char *str)
{
	token_t *token;

	if (str[0] == '&' && str[1] == '&')
	{
		token = token_new(NULL, T_AND);
		if (token == NULL || list_push_back(tokens, token) == 0)
		{
			token_del(token);
			return (-1);
		}
		return (2);
	}
	return (0);
}

/**
 * recognize_semicolon - recognize semicolon(;) token
 * @tokens: list to push token to
 * @str: test subject
 * Return: -1: error, 1: success, 0: not recognizable
*/
int recognize_semicolon(list_t *tokens, const char *str)
{
	token_t *token;

	if (str[0] == ';')
	{
		token = token_new(NULL, T_SEMICOLON);
		if (token == NULL || list_push_back(tokens, token) == 0)
		{
			token_del(token);
			return (-1);
		}
		return (1);
	}
	return (0);
}

/**
 * recognize_word - recognize word token
 * @tokens: list to push token to
 * @str: test subject
 * Return: -1: error, word_len: success, 0: not recognizable
*/
int recognize_word(list_t *tokens, const char *str)
{
	token_t *token;
	size_t len;
	char *value;

	len = 0;
	while (str[len] != '\0' && str[len] != ' ')
	{
		if (str[len] == ';')
			break;
		if (str[len] == '|' && str[len + 1] == '|')
			break;
		if (str[len] == '&' && str[len + 1] == '&')
			break;
		len++;
	}
	if (len == 0)
		return (0);
	value = _substr(str, 0, len);
	if (value == NULL)
		return (-1);
	token = token_new(value, T_WORD);
	if (token == NULL)
	{
		free(value);
		return (-1);
	}
	if (list_push_back(tokens, token) == 0)
	{
		token_del(token);
		return (-1);
	}
	return (len);
}

/**
 * tokenize - recognize all tokens in str
 * @str: test subject
 * Return: list of tokens or NULL
*/
list_t *tokenize(const char *str)
{
	list_t *tokens;
	int i;
	int fi;
	int len;
	recognizer_t recognizers[] = {
		recognize_or,
		recognize_and,
		recognize_semicolon,
		recognize_word,
	};

	tokens = list_new();
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ')
			i++;
		fi = 0;
		while (fi < 4)
		{
			len = recognizers[fi](tokens, str + i);
			if (len > 0)
				break;
			if (len == -1)
			{
				/* free and return NULL */
			}
			fi++;
		}
		i += len;
	}
	return (tokens);
}
