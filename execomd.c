#include "shell.h"

/**
 * c_exit - SHould frees user's typed comd and 
 * linked list before exiting
 * @str: The user's typed comd
 * @env: input the linked list of env
 */

void c_exit(char **str, list_t *env)
{
	free_double_ptr(str);
	free_linked_list(env);
	_exit(0);
}

/**
 * _execve - Should execute comd user typed into shell
 * @s:The  comd the user typed
 * @env: The env var
 * @num:The nth user comd;That is to be used in error message
 *
 * Return: 0 on success
 */

int _execve(char **s, list_t *env, int num)
{
	char *holder;
	int status = 0, t = 0;
	pid_t pid;

	/* For checking if command is absolute path */
	if (access(s[0], F_OK) == 0)
	{
		holder = s[0];
		t = 1;
	}

	/* If not, then flesh out full path */
	else
		holder = _which(s[0], env);
	/* And if it is not an executable, free */
	if (access(holder, X_OK) != 0)
	{
		not_found(s[0], num, env);
		free_double_ptr(s);
		return (127);
	}
	else /* If not, then fork and execute executable command */
	{
		pid = fork();
		if (pid == 0) /* And if its child process, execute */
		{
			if (execve(holder, s, NULL) == -1)
			{
				not_found(s[0], num, env); /* A special err msg */
				c_exit(s, env);
			}
		}
		else /* And if parent, wait for child then free all */
		{
			wait(&status);
			free_double_ptr(s);
			if (t == 0)
				free(holder);
		}
	}
	return (0);
}
