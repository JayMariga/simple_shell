#include "shell.h"

/**
 * c_strdup - This is the custom string duplication;
 * and excludes beginning bytes
 * @str: This is the string to duplicate
 * (e.g. environmental variable PATH=/bin:/bin/ls)
 * @cs: The no of bytes to exclude (e.g. excludes "PATH=")
 *
 * Return: A duplicate string (e.g. /bin:/bin/ls)
 */

char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int i, len = 0;

	/* This is to validate str input */
	if (str == NULL)
	return (NULL);

	/* calculates the len + null terminator to malloc */
	while (*(str + len))
		len++;
	len++;

	/* allocate memory but exclude environmental variable title */
	duplicate_str = malloc(sizeof(char) * (len - cs));
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(duplicate_str + i) = *(str + cs + i);
		i++;
	}
	return (duplicate_str);
}


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
