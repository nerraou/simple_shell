#include "main.h"

/**
 * env_del - delete env entry
 * @env: env entry
 */
void env_del(env_t *env)
{
	if (env == NULL)
		return;
	free(env->key);
	free(env->value);
	free(env);
}
