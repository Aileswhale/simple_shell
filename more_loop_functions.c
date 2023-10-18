#include "aileswhale.h"

/**
 * new_help_else_builtin - prints an error message
 *      if the command is not found
 * @vars: if command matches a builtin name,
 *      text files is sent to the standard output
 * Return: 0 if sucess
 */

void new_help_else_builtin(vars_t *vars)
{

	print_error_message(vars, ": no help topics match: `");
	_print_error(vars->array_tok[1]);

	_print_error("'.  Try `help help' or `man -k ");
	_print_error(vars->array_tok[1]);
	_print_error("' or `info ");
	_print_error(vars->array_tok[1]);
	_print_error("'.");

	_print_error("\n");
}

/**
 *new_help_alias_builtin - Implements a new help alias
 *	for the built-in function
 * @vars: Pointer to the structure holding variables
 * Return: 0 if sucess
 */

void new_help_alias_builtin(vars_t *vars)

{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "alias") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/alias";
		f_d = open(files, O_RDWR);

		s = malloc(300);
		if (s == NULL)
		{
			_print_error("Error");
			return;
		}
		while ((r = read(f_d, s, 300)) > 0)
		{
			r = write(1, s, r);
			print_msg("\n");
			if (r == -1)
			{
				_print_error("Error");
				return;
			}
		}
		free(s);
		f_d = close(f_d);
	}

	else
		new_help_else_builtin(vars);
}
