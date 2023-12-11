#include "shell.h"

/**
 * _execve - Will execute command typed into shell
 * @s: Is the command the user typed
 * @env: This is an environmental variable
 * @num: This is the nth user command; to be used in error message
 *
 * Return: 0 on success
 */

int _execve(char **s, list_t *env, int num)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	/* Is the command an absolute path? */
	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}

	/* else proceed to flesh out full path */
	else
		holder = _which(s[0], env);

	/* Free if it is not an executable, use 127 */
	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}

	/* else fork and execute executable command */
	else
	{
		pid = fork();
		if (pid == 0) /* incase it is a child process, execute */
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env);
				c_exit(s, env);
			}
		}

		/* if parent process, wait for child then free all */
		else
		{
			wait(&status);
			free_double_ptr(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}



/**
 * c_exit - Deallocates memory used for the input command and the
 * linked list before program termination.
 * @str: user's input command to deallocate.
 * @env: Linked list rep environment var to deallocate.
 */

void c_exit(char **str, list_t *env)
{
	/* release the memory allocated for the input command */
	free_double_ptr(str);

	/* Release the memory allocated for the linked list of env var */
	free_linked_list(env);

	_exit(0);
}

