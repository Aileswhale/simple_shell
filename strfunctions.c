#include "main.h"

/*** WRITES STRING TO STDOUT ***/
/**
 * _print - writes a string to standard output
 * @string: string to write
 *
 * Return: number of chars printed or -1 on failure
 */
ssize_t _print(char *string)
{
	ssize_t i, length;

	for (i = 0; string[i]; i++)
		;
	length = write(1, string, i);
	if (length != i)
	{
		perror("Fatal Error");
		return (-1);
	}
	return (length);
}
