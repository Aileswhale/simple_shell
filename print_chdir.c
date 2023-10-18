#include "aileswhale.h"
/**
 * print_cdir_1 - Prints an error message when the 'cd' argument is invalid,
 *               for example, 'cd -asd22'.
 * @vars: The variables parameter to include.
 * Return: This function always returns void and prints the following message.
 */
void print_cdir_1(vars_t *vars)
{
	print_string("-bash: cd: ", 1);
	print_string(vars->array_tok[1], 1);
	print_string(": invalid option", 0);
	print_string("cd: usage: cd [-] [--]", 0);
}

/**
 * print_cdir_2 - Prints an error message if the specified cd
 * argument does not exist. For example, if the argument is 'cd das7d32'.
 * @vars: Parameter to include vars
 * Return: Always returns void and prints the following message.
 */

void print_cdir_2(vars_t *vars)
{
	print_string("-bash: cd: ", 1);
	print_string(vars->array_tok[1], 1);
	print_string(": Not a directory", 0);
}
