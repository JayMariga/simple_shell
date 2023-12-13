#include "shell.h"


/**
 * main - Entry point for a simple shell
 * @ac: This is the no. of command-line arguments
 * @av: Array of strings rep command-line arguments
 * @env: Array of strings rep the environment.
 *
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	/* Suppress compiler warning on unused parameters. */
	(void)ac;
	(void)av;

	/* Call function to start the prompt. */
	prompt(env);
	return (0);
}
