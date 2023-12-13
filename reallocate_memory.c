#include "shell.h"

/**
 * _realloc - Reallocate memory and initialize new with 0
 * @ptr: This is the pointer to the memory
 * previously allocated (malloc(old_size))
 * @old_size: This is the size previously allocated
 * @new_size: The new size to reallocate
 *
 * Return: A pointer to the reallocated memory
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	unsigned int i;

	/* Free  memory if reallocating to 0 */
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	/* Return pointer if reallocating to the same old size */
	if (new_size == old_size)
		return (ptr);

	/* Allocate new size if pointer is originally null */
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		else
			return (p);
	}

	/* Check for errors after malloc */
	p = malloc(new_size);
	if (p == NULL)
		return (NULL);


	/* fill up values up to the min of old or new size */
	for (i = 0; i < old_size && i < new_size; i++)
		*((char *)p + i) = *((char *)ptr + i);
	free(ptr); /* We now free old ptr */

	return (p);
}
