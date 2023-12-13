#include "shell.h"

/**
 * ctrl_c - Handle Ctrl-c signal, to ignore input the
 * prints the prompt.
 * @n: Takes the int value from signal.
 */

void ctrl_c(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * built_in - should handle builtins (exit, env, cd)
 * @token: user's typed command tokens
 * @env: env variable linked lists
 * @num: Should take nth user command typed to write error message
 * @command: The command array to free
 *
 * Return: 1 if acted on builtin command, 0 if not.
 */

int built_in(char **token, list_t *env, int num, char **command)
{
	int i = 0;

	/* if user types "exit", free the command tokens, and exit */
	if (_strcmp(token[0], "exit") == 0)
	{
		i = __exit(token, env, num, command);
	}

	/* if user types "env", print, free the command tokens, and reprompt */
	else if (_strcmp(token[0], "env") == 0)
	{
		_env(token, env);
		i = 1;
	}

	/* if user types "cd", it will change the dir */
	else if (_strcmp(token[0], "cd") == 0)
	{
		i = _cd(token, env, num);
	}

	/* if user types "setenv", It creates or modify linked list node */
	else if (_strcmp(token[0], "setenv") == 0)
	{
		_setenv(&env, token);
		i = 1;
	}

	/* if user types "unsetenv", remove linked list node */
	else if (_strcmp(token[0], "unsetenv") == 0)
	{
		_unsetenv(&env, token);
		i = 1;
	}
	return (i);
}

/**
 * ignore_space - Should return string without the spaces in front
 * @str: Is the string
 *
 * Return: new string
 */

char *ignore_space(char *str)
{
	while (*str == ' ')
		str++;
	return (str);
}

/**
 * ctrl_D - Should exit program if Ctrl-D was pressed
 * @i: The chars read via get_line
 * @command: The user's typed in comd
 * @env: Is the env variable linked list
 */

void ctrl_D(int i, char *command, list_t *env)
{
	if (i == 0) /* SHould handle Ctrl+D */
	{
		free(command); /* Will help exit with newline if in shell */
		free_linked_list(env);
		if (isatty(STDIN_FILENO))/* ctrl+d should print newline */
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
}

/**
 * prompt - Should repeatedly prompts user and
 * executes user's cmds if applicable
 * @en: The env variables
 *
 * Return: 0 on success
 */

int prompt(char **en)
{
	list_t *env;
	size_t i = 0, n = 0;
	int command_line_no = 0, exit_stat = 0;
	char *command, *n_command, **token;

	env = env_linked_list(en);
	do {
		command_line_no++;
		if (isatty(STDIN_FILENO)) /* Should reprompt if in interactive shell */
			write(STDOUT_FILENO, "$ ", 2);
		else
			non_interactive(env);
		signal(SIGINT, ctrl_c); /* It makes ctrl+c not work */
		command = NULl;
		i = 0; /* Will reset vars each time loop runs */

		i = get_line(&command); /* WIll help read user's cmd in stdin */
		ctrl_D(i, command, env); /* Hence exits shell if ctrl-D */
		n_command = command;
		command = ignore_space(command);
		n = 0;
		while (command[n] != '\n') /* Should replace get_line's \n with \0 */
			n++;
		command[n] = '\0';

		if (command[0] == '\0') /* reprompt incase user hits enter only */
		{
			free(n_command);
			continue;
		}
		token = NULL;
		token = _str_tok(command, " "); /* This is token user cmd*/
		if (n_command != NULL)
			free(n_command);
		exit_stat = built_in(token, env, command_line_no, NULL);
		if (exit_stat)
			continue;
		exit_stat = _execve(token, env, command_line_no);
	} while (1); /* Continues repeating till user exits shell */
	return (exit_stat);
}
