#include "shell.h"

/**
 * c_strdup - This is the custom string duplication;
 * and excludes beginning bytes
 * @str: This is the string to duplicate
 * (e.g. environmental variable PATH=/bin:/bin/ls)
 * @cs: The no of bytes to exclude (e.g. excludes "PATH=")
 *
 * Return: A duplicate string (e.g. /bin:/bin/ls)
 */

char *c_strdup(char *str, int cs)
{
	char *duplicate_str;
	int i, len = 0;

	/* This is to validate str input */
	if (str == NULL)
		return (NULL);

	/* calculates the len + null terminator to malloc */
	while (*(str + len))
		len++;
	len++;

	/* allocate memory but exclude environmental variable title */
	duplicate_str = malloc(sizeof(char) * (len - cs));
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < (len - cs))
	{
		*(duplicate_str + i) = *(str + cs + i);
		i++;
	}
	return (duplicate_str);
}
