#include "main.h"

/**
 * print_cdir_1 - Prints error when cd argument in invalid
 *              i.e. cd -asd22
 * @vars: vars parameter to include
 * Return: Always return void and print a messaje as shown below.
 */
void print_cdir_1(vars_t *vars)
{
	print_string("-bash: cd: ", 1);
	print_string(vars->array_tok[1], 1);
	print_string(": invalid option", 0);
	print_string("cd: usage: cd [-] [--]", 0);
}

/**
 * print_cdir_2 - Prints error message when cd argument doesn'n exist.
 *              i.e. cd das7d32
 * @vars: vars parameter to include
 * Return: Always return void and print a messaje as shown below.
 */
void print_cdir_2(vars_t *vars)
{
	print_string("-bash: cd: ", 1);
	print_string(vars->array_tok[1], 1);
	print_string(": Not a directory", 0);
}
