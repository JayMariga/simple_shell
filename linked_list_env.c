#include "shell.h"

/**
 * env_linked_list - Should create a linked list from env var.
 * @env: env variables
 *
 * Return: The linked list
 */

list_t *env_linked_list(char **env)
{
	list_t *head;
	int i = 0;

	head = NULL;
	while (env[i] != NULL)
	{
		add_end_node(&head, env[i]);
		i++;
	}
	return (head);
}

/**
 * _env - Should print env variables.
 * @str: Is the user's command into shell (i.e. "env")
 * @env: env variables
 *
 * Return: 0 if a success
 */
int _env(char **str, list_t *env)
{
	/* Free the user input */
	free_double_ptr(str);
	/* Will print the environment. */
	print_list(env);
	return (0);
}
