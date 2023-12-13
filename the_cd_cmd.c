#include "shell.h"

/**
 * c_strcat - Should concatenate two strings
 * ignoring first character ("~" in cd)
 * @dest: The string to appended to
 * @src: The string that is to be  appended.
 *
 * Return: The concatenated string
 */

char *c_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	/* Search for total length of both strings to realloc */
	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	/* realloc because the dest was malloced outside of function */
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	/* the first character to be ignored. */
	j = 1;
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}

/**
 * c_setenv - This is the custom _setenv by concatenating
 * A string first before setting
 * @env: IS the env variable linked list
 * @name: Is the env variable name (e.g. "OLDPWD")
 * @dir: directory path like (e.g. "/home/vagrant/directory1")
 *
 * Return: 0 if a success (e.g. "OLDPWD=/home/vagrant/directory1")
 */

int c_setenv(list_t **env, char *name, char *dir)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	/* form a new concatenated string */
	cat = _strdup(name);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, dir);
	/* We now get index to env var in linked list */
	index = find_env(*env, name);

	/* traverse to idx */
	holder = *env;
	while (j < index)
	{
		holder = holder->next;
		j++;
	}
	free(holder->var);
	holder->var = _strdup(cat);
	free(cat);
	return (0);
}

/**
 * cd_only - We change the directory to home
 * @env: Should bring in env linked list to update PATH and OLDPWD
 * @current: Should take us to current working directotry
 */

void cd_only(list_t *env, char *current)
{
	char *home = NULL;

	home = get_env("HOME", env);
	/* updated env oldpwd */
	c_setenv(&env, "OLDPWD", current);
	free(current);
	/* Go to home dir if it exists */
	if (access(home, F_OK) == 0)
		chdir(home);
	current = NULL;
	current = getcwd(current, 0);
	/* updated pwd env */
	c_setenv(&env, "PWD", current);
	free(current);
	free(home);
}


/**
 * cd_execute - Should execute the cd
 * @env: Should take us to environmental linked list
 * to update PATH and OLDPWD
 * @current: Should take us to current working directotry
 * @dir: This is the directory path to change to
 * @str: This is the argument to write out error
 * @num: This is the line number to write out error
 *
 * Return: 0 if it's a success 2 if fail
 */

int cd_execute(list_t *env, char *current, char *dir, char *str, int num)
{
	int i = 0;

	if (access(dir, F_OK) == 0)
	{
		/* Should update env oldpwd */
		c_setenv(&env, "OLDPWD", current);
		free(current);
		chdir(dir);
		current = NULL;
		/* we get to the current working dir */
		current = getcwd(current, 0);
		/* The update env pwd */
		c_setenv(&env, "PWD", current);
		free(current);
	}
	else
	{
		cant_cd_to(str, num, env);
		free(current);
		i = 2;
	}
	return (i);
}

/**
 * _cd - This is change directory function
 * @str: This is the user's typed in command
 * @env: The env linked list to retrieve HOME and OLDPWD paths
 * @num: The nth user command, used at error message
 *
 * Return: 0 if it's a success 2 if failed
 */

int _cd(char **str, list_t *env, int num)
{
	char *current = NULL, *dir = NULL;
	int exit_stat = 0;

	/* the current working directory */
	current = getcwd(current, 0);
	if (str[1] != NULL)
	{
		/* the usage of cd~ */
		if (str[1][0] == '~')
		{
			dir = get_env("HOME", env);
			dir = c_strcat(dir, str[1]);
		}
		/* cd - */
		else if (str[1][0] == '-')
		{
			if (str[1][1] == '\0')
				dir = get_env("OLDPWD", env);
		}
		/* cd directory 1 */
		else
		{
			if (str[1][0] != '/')
			{
				dir = getcwd(dir, 0);
				dir = _strcat(dir, "/");
				dir = _strcat(dir, str[1]);
			}
			else
				dir = _strdup(str[1]);
		}
		exit_stat = cd_execute(env, current, dir, str[1], num);
		free(dir);
	}
	/* cd itself */
	else
		cd_only(env, current);
	/* should free the users input */
	free_double_ptr(str);
	return (exit_stat);
}
