#include "shell.h"

/**
 * _strcmp - Function to compare two strings
 * @s1: The string 1
 * @s2: Then string 2
 *
 * Return: integer that tells num spaces in between,
 * 0 if it is exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) == *(s2 + i) && *(s1 + i))
		i++;

	if (*(s2 + i))
		return (*(s1 + i) - *(s2 + i));
	else
		return (0);
}
