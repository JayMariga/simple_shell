#include "shell.h"

/**
 * _strdup - Should return a pointer to a newly allocated space in memory,
 * which has a copy of the string given as a parameter
 * @str: The String to duplicate
 *
 * Return: A pointer to duplicated string in the allocated memory
 */

char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	/* We validate string input */
	if (str == NULL)
		return (NULL);

	while (*(str + len))
		len++;
	len++;

	/* We now allocate memory */
	duplicate_str = malloc(sizeof(char) * len);
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		*(duplicate_str + i) = *(str + i);
		i++;
	}

	return (duplicate_str);
}
