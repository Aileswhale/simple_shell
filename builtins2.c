#include "main.h"
/**
 * new_the_cd - Changes the current working directory .
 * if no parameter is passed it will change directory to HOME.
 * @vars: A string representing the input from the user.
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
