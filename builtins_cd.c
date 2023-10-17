#include "main.h"

/**
 * new_the_cd - Modifies the current working directory.
 * If no parameter is provided, it changes the directory to HOME.
 * @vars: A string containing the user input.
 */

void new_the_cd(vars_t *vars)
{
	int i;

	if (vars->array_tok[1] == NULL)
	{
		i = env_path(*vars, "HOME");
		chdir((vars->env[i]) + 5);
	}
	else if (strcmp(vars->array_tok[1], "-") == 0)
		print_string(vars->array_tok[1], 0);
	else
		chdir(vars->array_tok[1]);
}
