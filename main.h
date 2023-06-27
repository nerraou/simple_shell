#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#include "lib.h"
#include "list.h"
#include "parser.h"

#define BUILTINS_COUNT 1

typedef int (*builtin_function_t)();

/**
 * struct env_s - env variable
 * @key: env key
 * @value: env value
 *
 * Description: env entry
 */

typedef struct env_s
{
	char *key;
	char *value;
} env_t;

/**
 * struct shell_s - shell globals
 * @last_command_status: last executed command status
 * @last_exit_code: last executed command exit code
 * @envs: array of envs variales
 *
 * Description: contains all globals needed by the shell
 */
typedef struct shell_s
{
	int last_command_status;
	int last_exit_code;
	list_t *envs;
} shell_t;

/**
 * struct builtin_s - builtin function
 * @name: command name
 * @action: builtin action
 *
 * Description: contains builtin function data
 */
typedef struct builtin_s
{
	char *name;
	builtin_function_t action;
} builtin_t;

int shell_init(shell_t *shell, char *env[]);
char *_readline(const char *prompt);
void eval(shell_t *shell);

int execute(shell_t *shell, char **argv, char **env);
void execute_list(shell_t *shell, list_t *commands);
void free_grid(char **grid);

env_t *env_parse(const char *str);
list_t	*env_init(char *env_arr[]);
void env_del(env_t *env);
char *_getenv(const list_t *envs, const char *name);

int bi_exit(int ac, char **av, char **env, shell_t *shell, list_t *tokens);

#endif /* MAIN_H */
