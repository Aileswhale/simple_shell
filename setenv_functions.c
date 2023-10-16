#include "main.h"

/**
 * add_values - create a new environment variable string
 * @keys:the vriable name
 * @values: variable values
 *
 * Return: pointer to the new string;
 */


char *add_values(char *keys, char *values)
{
	unsigned int length1, length2, i, j;
	char *new;

	length1 = strlen(keys);
	length2 = strlen(values);
	new = malloc(sizeof(char) * (length1 + length2 + 2));
	if (new == NULL)
		return (NULL);
	for (i = 0; keys[i] != '\0'; i++)
		new[i] = keys[i];
	new[i] = '=';
	for (j = 0; values[j] != '\0'; j++)
		new[i + 1 + j] = values[j];
	new[i + 1 + j] = '\0';
	return (new);
}

/**
 * find_keys - finds an environment variable
 * @env:an  array containing  environment variables
 * @keys: environment variable to find
 *
 * Return:a pointer to address of the environment variable
 */

char **find_keys(char **env, char *keys)
{
	unsigned int i, j, length1;

	length1 = strlen(keys);
	for (i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < length1; j++)
		{
			if (keys[j] != env[i][j])
				break;
		}
		if (j == length1 && env[i][j] == '=')
			return (&env[i]);
	}
	return (NULL);
}

/**
 * add_keys - create a new environment variable
 * @vars:a pointer to the structure of variables
 *
 * Return: void
 */
void add_keys(vars_t *vars)
{
	unsigned int i;
	char **new_env;

	for (i = 0; vars->env[i] != NULL; i++)
		;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (new_env == NULL)
	{
		print_error_message(vars, NULL);
		vars->status = 127;
		exit_program(vars);
	}
	for (i = 0; vars->env[i] != NULL; i++)
		new_env[i] = vars->env[i];
	new_env[i] = add_values(vars->array_tok[1], vars->array_tok[2]);
	if (new_env[i] == NULL)
	{
		print_error_message(vars, NULL);
		free(vars->buff);
		free(vars->cmd);
		free(vars->array_tok);
		free_shell_env(vars->env);
		free(new_env);
		exit(127);
	}
	new_env[i + 1] = NULL;
	free(vars->env);
	vars->env = new_env;
}
