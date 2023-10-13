#include "main.h"

/**
 * _print_error - print a string to sdandart error
 * @string: string to print.
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

/**** imprime mensage de error con ciertor parametros ****/
/**
 * print_error_message - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @message: message to print
 *
 * Return: void
 */

void print_error_message(vars_t *vars, char *message)
{
	char *counter;

	_print_error(vars->argv[0]);
	_print_error(": ");

	/*aqui croe una funcion para convertir un entero a string*/
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
 * int_converter - converts an unsigned int to a string
 * @counter: unsigned int to convert
 *
 * Return: pointer to the converted string
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
