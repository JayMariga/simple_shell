#include "shell.h"

/**
 * get_env - Locates and returns a copy of the requested env variable
 * @str: The string to store result in
 * @env: The complete set of environmental variables
 *
 * Return: copy of specified env variable
 */

char *get_env(char *str, list_t *env)
{
	int j = 0, cs = 0;

	while (env != NULL)
	{
		j = 0;
		/* Help us find desired env variable */
		while ((env->var)[j] == str[j])
			j++;
		if (str[j] == '\0' && (env->var)[j] == '=')
			break;
		env = env->next;
	}

	while (str[cs] != '\0')
		cs++;
	cs++;
	return (c_strdup(env->var, cs));
}
