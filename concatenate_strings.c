#include "shell.h"

/**
 * _strcat - Should concatenate two strings
 * @dest: This is the string to be appended to
 * @src: The string to append
 * Return: The concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	/* To find the total length of both strings for _realloc */
	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	/* _realloc because dest was allocated outside of the function */
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	/* copy the chars from src to the dest. */
	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}
