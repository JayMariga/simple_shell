#include "shell.h"

/**
 * __exit - It frees user input and then exits main program with a value
 * @str: user's command into the shell (e.g.. "exit 99")
 * @env: Env variable to fgree at error
 * @num: The nth user command line input to print in the error message
 * @command: The command to free
 *
 * Return: 0 if successful, and  2 if fail
 */

int __exit(char **str, list_t *env, int num, char **command)
{
	int e_value = 0;

	/* If there is no value after exit, return 0 */
	if (str[1] != NULL)
		e_value = c_atoi(str[1]);

	/* If value after exit is invalid, its an error. perror */
	if (e_value == -1)
	{
		illegal_number(str[1], num, env); /*Pprint the error msg */
		free_double_ptr(str);
		return (2);
	}

	/* User input to be freed before exiting the program */
	free_double_ptr(str);
	free_linked_list(env);

	if (command != NULL)
		free_double_ptr(command);

	exit(e_value);
}
