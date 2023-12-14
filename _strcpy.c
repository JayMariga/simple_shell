#include "shell.h"


/**
 * _strlen - Should return the length of a string.
 * @s: Pointer to char string.
 *
 * Return: The length of char string.
 */

int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
 * _strcpy - Should copy the string pointed to by src, with the
 * terminating null byte, to the buffer pointed.
 * @dest: This is the pointer to the destination of copied string.
 * @src: Pointer to the src of source string.
 *
 * Return: Pointer to destination.
 */

char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Should concantenates 2 strings.
 * @dest: This is the pointer to the destination string.
 * @src: This is the Pointer to source string.
 *
 * Return: Pointer to destination
 */

char *_strcat(char *dest, const char *src)
{
	char *destTemp;
	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	while (*destTemp != '\0')
		destTemp++;

	while (*srcTemp != '\0')
		*destTemp++ = *srcTemp++;
	*destTemp = '\0';
	return (dest);
}

/**
 * _strncat - Concantenates two strings in an instance where
 * n number of bytes are copied from source.
 * @dest: This is the pointer to destination string.
 * @src: This is the pointer to source string.
 * @n: The n bytes to copy from src.
 *
 * Return: Pointer to destination.
 */

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return (dest);
}
