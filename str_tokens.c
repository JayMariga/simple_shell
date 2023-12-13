#include "shell.h"

/**
 * t_strlen - Returns the lenght of a token string for the dynamic memory
 * allocation
 * @str: This is a token from user's cmd
 * @pos: index position in user's command typed into the shell
 * @delm: The delimeter (e.g. " ");
 *
 * Return: The token length
 */
int t_strlen(char *str, int pos, char delm)
{
	int len = 0;

	while ((str[pos] != delm) && (str[pos] != '\0'))
	{
		pos++;
		len++;
	}
	return (len);
}


/**
 * t_size - SHould return no of delimeters ignoring continuous delims
 * @str: Should be user's command typed into shell
 * @delm: The delimeter (e.g. " ");
 *
 * Return: No of delims so that (num token = delims + 1)
 */

int t_size(char *str, char delm)
{
	int i = 0, num_delm = 0;

	while (str[i] != '\0')
	{
		if ((str[i] == delm) && (str[i + 1] != delm))
		{
			/* Should handle continuous delims */
			num_delm++;
		}
		if ((str[i] == delm) && (str[i + 1] == '\0'))
		{
			/* Should handle continuous delims after full command */
			num_delm--;
		}
		i++;
	}
	return (num_delm);
}

/**
 * ignore_delm - Should return a version of string without preceeding delims
 * @str: A string
 * @delm: The delimiter (e.g. " ")
 *
 * Return: A new string in (e.g. "    ls -l" --> "ls -l")
 */

char *ignore_delm(char *str, char delm)
{
	while (*str == delm)
		str++;
	return (str);
}

/**
 * _str_tok - Should tokenize a string and returns an array of tokens
 * @str: The user's command typed into the shell
 * @delm: The delimeter (e.g. " ");
 *
 * Return: An array of tokens in (e.g. {"ls", "-l", "/tmp"}
 */

char **_str_tok(char *str, char *delm)
{
	int buffsize = 0, p = 0, si = 0, i = 0, len = 0, se = 0, t = 0;
	char **toks = NULL, d_ch;

	d_ch = delm[0];

	/* creates a new version of string ignoring all delimiters infront*/
	str = ignore_delm(str, d_ch);

	/* malloc pointers to store array of tokens (buffsize + 1), and NULL ptr */
	buffsize = t_size(str, d_ch);
	toks = malloc(sizeof(char *) * (buffsize + 2));
	if (toks == NULL)
		return (NULL);
	while (str[se] != '\0')	/* Find the string ending index */
		se++;
	while (si < se)
	{ 
		/* malloc lengths for each token pointer in the array */
		if (str[si] != d_ch)
		{
			len = t_strlen(str, si, d_ch);
			toks[p] = malloc(sizeof(char) * (len + 1));
			if (toks[p] == NULL)
				return (NULL);
			i = 0;
			while ((str[si] != d_ch) && (str[si] != '\0'))
			{
				toks[p][i] = str[si];
				i++;
				si++;
			}
			toks[p][i] = '\0'; /* Null terminate at the end*/
			t++;
		}

		/* We handle repeated delims; increment pointer after ("ls __-l")*/
		if (si < se && (str[si + 1] != d_ch && str[si + 1] != '\0'))
			p++;
		si++;
	}
	p++;
	toks[p] = NULL; /* set the last array pointer to NULL */
	return (toks);
}
