#include "shell.h"

/**
 * find_env - Searches for a specific envitonmrntal variable
 * in a linked list.
 * @env: Pointer to the environmental variable linked list
 * @str: variable name that is to be searched.
 *
 * Return: idx of node in linked list
 */

int find_env(list_t *env, char *str)
{
	int j = 0, index = 0;

	while (env != NULL)
	{
		j = 0;
		/* finding the desired env var */
		while ((env->var)[j] == str[j])
			j++;
		/* And if it matches , break, and return idx */
		if (str[j] == '\0')
			break;
		env = env->next;
		index++;
	}
	if (env == NULL)
		return (-1);

	return (index);
}

/**
 * _unsetenv - Should remove node in env linked list
 * @env: Pointer to a linked list
 * @str: User's input command (e.g. "unsetenv MAIL")
 *
 * Return: 0 on success
 */

int _unsetenv(list_t **env, char **str)
{
	int index = 0, j = 0;

	if (str[1] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	index = find_env(*env, str[1]);/* Get index of the node to delete */
	/* Free memory and check if index is not found, hence error */
	free_double_ptr(str);
	if (index == -1)
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	j = delete_nodeint_at_index(env, index); /* delete node */
	if (j == -1) /* Error if deletion failed */
	{
		write(STDOUT_FILENO, "Cannot find\n", 12);
		return (-1);
	}
	return (0);
}


/**
 * _setenv - Modifies an environmental variable in linked list
 * @env: Pointer to linked list
 * @str: user's input command (e.g. "setenv USER Superman")
 *
 * Return: 0 If it's a success, 1 on failure
 */

int _setenv(list_t **env, char **str)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;
	/* Checking if arguments are enough */
	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	/* Concatenates string to form new node data */
	cat = _strdup(str[1]);
	cat = _strcat(cat, "=");
	cat = _strcat(cat, str[2]);
	/* Find the index to traverse to the new node */
	index = find_env(*env, str[1]);
	/* Checking if environment var exists */
	if (index == -1)
	{
		add_end_node(env, cat);
	}
	else
	{
		holder = *env;
		/* Traverse node in the linked list */
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		/* Free previous allocated data and assign new data */
		free(holder->var);
		holder->var = _strdup(cat);
	}
	free(cat); /* free memory and returning success */
	free_double_ptr(str);
	return (0);
}
