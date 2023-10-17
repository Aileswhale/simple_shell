#include "aileswhale.h"

/**
 * _print_error -helps print a string to a sdandard  error
 * @string:the string to be printed.
 * Return: void
 */

void _print_error(char *string)
{
	long number, length;

	number = strlen(string);
	length = write(STDERR_FILENO, string, number);
	if (length != number)

	{
		perror("fatal error");
		exit(100);
	}
}

/**
 * print_error_message - Prints error messages to standard error
 * @vars: Pointer to a structure of variables
 * @message: Message to be printed
 *
 * Return: void
 */


void print_error_message(vars_t *vars, char *message)
{
	char *counter;

	_print_error(vars->argv[0]);
	_print_error(": ");


	counter = int_converter(vars->vars_counter);
	_print_error(counter);
	free(counter);
	_print_error(": ");
	_print_error(vars->array_tok[0]);
	if (message)
	{
		_print_error(message);
	}
	else
		perror("");
}

/**
 * int_converter - Converts an unsigned integer to a string
 * @counter: an unsigned integer to be converted
 *
 * Return: the pointer to the converted string
 */

char *int_converter(unsigned int counter)
{
	char *num_str;
	unsigned int temporary, digts;

	temporary = counter;

	for (digts = 0; temporary != 0; digts++)
		temporary /= 10;

	num_str = malloc(sizeof(char) * (digts + 1));

	if (num_str == NULL)
	{
		perror("Error");
		exit(100);
	}


	num_str[digts] = '\0';

	for (--digts; counter; --digts)
	{
		num_str[digts] = (counter % 10) + '0';
		counter /= 10;
	}
	return (num_str);
}
