#include "shell.h"

/**
 * c_t_size - Should return no of delimiters.
 * @str: The user's command typed into a shell
 * @delm: The delimiter (e.g. " ");
 *
 * Return: no. of tokens
 */

int c_t_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if (str[i] == delm)
		{
			num_delm++;
		}
		i++;
	}
	return (num_delm);
}


/**
 * c_str_tok - tokenizes a string even with continuous delim with empty string
 * (e.g. path --> ":/bin::/bin/usr" )
 * @str: The user's command typed into shell
 * @delm: Delimeter in (e.g. " ");
 *
 * Return: An array of tokens (e.g. {"\0", "/bin", "\0", "/bin/usr"}
 *(The purpose is to the 'which' command look through current directory if ":")
 */

char **c_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0;
	char **toks = NULL, d_ch;

	/* set the variable to be the delimiter character (" ") */
	d_ch = delm[0];

	/* malloc number of pointers to store an array of tokens, and NULL ptr */
	buffsize = c_t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);

	/* We iterate from string index 0 to string ending index */
	while (str[se] != '\0')
		se++;
	while (si < se)
	{
		/* Malloc lengths for each token pointer in the array */
		len = t_strlen(str, si, d_ch);
		toks[p] = malloc(sizeof(char) * (len + 1));
		if (toks[p] == NULL)
			return (NULL);
		i = 0;
		while ((str[si] != d_ch) &&
		       (str[si] != '\0'))
		{
			toks[p][i] = str[si];
			i++;
			si++;
		}
		toks[p][i] = '\0';
		p++;
		si++;
	}
	toks[p] = NULL; /* We set the last array pointer to NULL */
	return (toks);
}
