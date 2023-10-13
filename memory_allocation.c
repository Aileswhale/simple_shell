#include "main.h"

/**
 * _realloc - reallocates a pointer to double the space
 * @pointer: pointer to the old array
 * @sizes: pointer to number of elements in the old array
 *
 * Return: pointer to the new array
 */
char **_realloc(char **pointer, size_t *sizes)
{
	char **new;
	size_t i;

	new = malloc(sizeof(char *) * ((*sizes) + 10));
	if (new == NULL)
	{
		free(pointer);
		return (NULL);
	}
	for (i = 0; i < (*sizes); i++)
	{
		new[i] = pointer[i];
	}
	*sizes += 10;
	free(pointer);
	return (new);
}
