#include "shell.h"

/**
 * _strcpy - Should copy a string that is pointed to by src,
 * and should include the terminating null byte (\0),
 * to buffer pointed to by dest
 *
 * @dest: Copies source to buffer
 * @src: Will be the source to copy
 *
 * Return: Pointer to the destination string source
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	/* Calculate the length of the source string */
	for (len = 0; src[len] != '\0'; len++)
		;

	/* copy each character from source to destination */
	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	/* Return the destination string */
	return (dest);
}
