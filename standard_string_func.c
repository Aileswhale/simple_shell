#include "aileswhale.h"


/**
 * _print - prints the string to the standard output
 * @string: string to print
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
