#include "shell.h"

/**
 * c_atoi - Custom atoi converts a string to an int
 * @s: The string to convert to an int.
 *
 * Return: Converted no. if success, -1 if string contains non-numbers
 */

int c_atoi(char *s)
{
	int i = 0;
	unsigned int num = 0;

	while (s[i] != '\0')
	{
		/* Account for num and calculates */
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		/* To look for non-numbers */
		if (s[i] > '9' || s[i] < '0')
			return (-1);
		i++;
	}
	return (num);
}
