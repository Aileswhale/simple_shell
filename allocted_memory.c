#include "aileswhale.h"

/**
 * reallocate - Doubles the space allocated for a pointer.
 * @pointer: Pointer to the original array.
 * @sizes: Pointer to the number of elements in the original array.
 *
 * Return: Pointer to the newly reallocated array.
 */

char **reallocate(char **pointer, size_t *sizes)
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
