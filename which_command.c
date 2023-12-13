#include "shell.h"

/**
 * _which - Completes a command by appending it to a matching PATH directory
 * @str: Innitial command user typed to shell (e.g. "ls" if user typed "ls -l")
 * @env: env variable linked list
 *
 * Return: A copy of Completed out command (e.g. "/bin/ls" if originally "ls")
 */

char *_which(char *str, list_t *env)
{
	char *pth, *cat = NULL, **toks;
	int i = 0;

	/* Get and tokenize PATH dir, then later free original string */
	pth = get_env("PATH", env);
	toks = c_str_tok(pth, ":");
	free(pth);

	/* Append "/cmd" to each token to see it's a legit cmd */
	i = 0;
	while (toks[i] != NULL)
	{
		if (toks[i][0] == '\0')
			cat = getcwd(cat, 0);
		else
			cat = _strdup(toks[i]);
		cat = _strcat(cat, "/");
		cat = _strcat(cat, str);
		if (access(cat, F_OK) == 0)
		{
			/* Free tokens before returning legit completed path */
			free_double_ptr(toks);
			return (cat);
		}
		free(cat); /* Free the concatenated str if cmd is never found */
		i++;
	}
	free_double_ptr(toks);
	return (str); /* Return original string if not found; won't pass execve */
}
