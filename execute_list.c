#include "main.h"

/**
 * prepare_env_entry - create key=value entry
 * @env: env entry
 * Return: allocated string or NULL
*/
char *prepare_env_entry(const env_t *env)
{
	char *str;
	size_t len;
	size_t key_len;

	key_len = _strlen(env->key);
	len = key_len + _strlen(env->value) + 2;
	str = malloc(sizeof(char) * (len));
	if (str == NULL)
		return (NULL);
	_strcpy(str, env->key);
	str[key_len] = '=';
	_strcpy(str + key_len + 1, env->value);
	return (str);
}

/**
 * create_env - create env entries
 * @shell: shell data
 * Return: array of env entries
*/
char **create_env(const shell_t *shell)
{
	char **env;
	node_t *it;
	int i;

	env = malloc(sizeof(char *) * (shell->envs->size + 1));
	if (env == NULL)
		return (NULL);
	i = 0;
	it = shell->envs->head;
	while (it != NULL)
	{
		env[i] = prepare_env_entry(it->data);
		if (env[i] == NULL)
		{
			free_grid(env);
			return (NULL);
		}
		i++;
		it = it->next;
	}
	env[i] = NULL;
	return (env);
}

/**
 * create_argv - create argv
 * @head: start node to create argv from
 * @argv: reference to set created argv to
 * @argc: reference to set created argc tos
 * Return: the node after the last found argument
*/
const node_t *create_argv(const node_t *head, char ***argv, int *argc)
{
	char **_argv;
	int _argc;
	const node_t *it;
	token_t *token;

	_argc = 0;
	if (head == NULL)
		return (NULL);
	it = head;
	while (it != NULL)
	{
		token = it->data;
		if (is_token_seperator(token->type))
			break;
		_argc += 1;
		it = it->next;
	}
	_argv = malloc(sizeof(char *) * (_argc + 1));
	if (_argv == NULL)
		return (NULL);
	_argc = 0;
	it = head;
	while (it != NULL)
	{
		token = it->data;
		if (is_token_seperator(token->type))
			break;
		_argv[_argc] = _strdup(token->value);
		if (_argv[_argc] == NULL)
		{
			free_grid(_argv);
			return (NULL);
		}
		_argc += 1;
		it = it->next;
	}
	_argv[_argc] = NULL;
	*argv = _argv;
	*argc = _argc;
	return (it);
}

/**
 * execute_builtin - execute simple command
 *@shell: shell data
 *@tokens: tokens list
 *@argc: command arguments count
 *@argv: command arguments value
 *@env: envs
 * Return: 0 on success or -1 on failure
 */
bool execute_builtin(shell_t *shell, list_t *tokens, int argc,
	char **argv, char **env)
{
	builtin_t builtins[BUILTINS_COUNT] = {
		{"cd", bi_cd},
		{"exit", bi_exit},
		{"env", bi_env},
		{"unsetenv", bi_unsetenv},
		{"setenv", bi_setenv},
	};
	int i;

	for (i = 0; i < BUILTINS_COUNT; i++)
	{
		if (_strcmp(argv[0], builtins[i].name) == 0)
			break;
	}
	if (i == BUILTINS_COUNT)
		return (false);
	shell->last_exit_code = builtins[i].action(argc, argv, env, shell, tokens);
	return (true);
}

/**
 * execute_list - execute list of commands
 * @shell: shell data
 * @commands: commands list
*/
void execute_list(shell_t *shell, list_t *commands)
{
	char **argv;
	int argc;
	char **env;
	const node_t *it;

	it = commands->head;
	while (1)
	{
		argc = 0;
		argv = NULL;
		env = create_env(shell);
		it = create_argv(it, &argv, &argc);
		if (argc > 0)
		{
			if (execute_builtin(shell, commands, argc, argv, env) == false)
			{
				if (execute(shell, argv, env) != 0)
					perror("./shell");
			}
		}
		free_grid(argv);
		free_grid(env);
		argv = NULL;
		if (it == NULL)
			break;
		it = it->next;
	}
}
