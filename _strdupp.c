#include "shell.h"

char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strchr - Should help locates a char in a string.
 * @s: String to be searched.
 * @c: Character to  locate.
 *
 * Return: Incase c is found - a pointer to the first occurence.
 * Else if not found - NULL.
 */

char *_strchr(char *s, char c)
{
	int index;

	for (index = 0; s[index]; index++)
	{
		if (s[index] == c)
			return (s + index);
	}

	return (NULL);
}

/**
 * _strspn - Should help get the length of a prefix substr.
 * @s: String to be searched.
 * @accept: Prefix to measure.
 *
 * Return: The no. of bytes in s which
 * Should consist only of bytes from accept.
 */

int _strspn(char *s, char *accept)
{
	int bytes = 0;
	int index;

	while (*s)
	{
		for (index = 0; accept[index]; index++)
		{
			if (*s == accept[index])
			{
				bytes++;
				break;
			}
		}
		s++;
	}
	return (bytes);
}

/**
 * _strcmp - It Compares 2 strings.
 * @s1: String 1 to be compared.
 * @s2: String 2 to be compared.
 *
 * Return: +ve byte difference if s1 > s2
 * 0 if s1 = s2
 * -ve byte difference if s1 < s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}

/**
 * _strncmp - It compares 2 strings.
 * @s1: Pointer 1 to a string.
 * @s2: Pointer 2 to a string.
 * @n: First n bytes of the strings.
 *
 * Return: >0 if s1 is shorter than s2.
 * 0 if s1 and s2 match.
 * <0 if s1 is longer than s2.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; s1[i] && s2[i] && i < n; i++)
	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
	}
	if (i == n)
		return (0);
	else
		return (-15);
}
