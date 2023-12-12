#include "shell.h"

/**
 * get_line - Reads user input from SI and stores it in
 * a dynamically allocated buffer.
 * @str: Pointer to the buffer.
 *
 * Return: No. of characters read
 */

size_t get_line(char **str)
{
	ssize_t i = 0, size = 0, t = 0, t2 = 0, n = 0;
	char buff[1024];

	/* Read input until a newline or buffer is filled; -1 to add a '\0' */
	while (t2 == 0 && (i = read(STDIN_FILENO, buff, 1024 - 1)))
	{

		/* Check if read found an error */
		if (i == -1)
			return (-1);

		/* Null-terminate the buffer with \0 to use with _strcat */
		buff[i] = '\0';

		/* Reset char index for \n check */
		n = 0;
		while (buff[n] != '\0')
		{
			if (buff[n] == '\n')
				t2 = 1;
			n++;
		}

		/* copy the read content to buff into get_line's buffer */
		if (t == 0) /* Malloc the first read */
		{
			i++;
			*str = malloc(sizeof(char) * i);
			*str = _strcpy(*str, buff);
			size = i;
			t = 1;
		}

		/* reallocate via _strcat with each loop after 1st read */
		else
		{
			size += i;
			*str = _strcat(*str, buff);
		}
	}
	return (size);
}
