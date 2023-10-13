#include "main.h"

/**
 * new_help_alias_builtin - help builtin command alias
 * @vars: if command matches a builtin name, text files is sent to stdout
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
/**
 * new_help_else_builtin -error message if not command found
 * @vars: if command matches a builtin name, text files is sent to stdout
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
