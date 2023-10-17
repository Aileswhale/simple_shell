#include "aileswhale.h"

/**
* make_shell_environment - creates the shell environment 
* 	from the provided environment.
 * @env: environment passed to main
 *
 * Return: a pointer to the newly created environment
 */
char **make_shell_enviroment(char **env)
{
	char **new_enviroment = NULL;

	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	new_enviroment = malloc(sizeof(char *) * (i + 1));
	if (new_enviroment == NULL)
	{
		perror("Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		new_enviroment[i] = strdup(env[i]);
	new_enviroment[i] = NULL;
	return (new_enviroment);
}

/**
 * free_shell_env - free the shell's environment
 * @env: shell's environment
 *
 * Return: void
 */
void free_shell_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}

/**
 * chdir_to_env - change directory to the location 
 * 	indicated by the environment variable's address.
 * @vars: structure variable of type vars_t.
 * @str: name of the targeted environment variable.
 * Return: Always returns void.
 */

void chdir_to_enviroment(vars_t *vars, char *str)
{
	int length, i;

	length = strlen(str);
	i = env_path(*vars, str);
	chdir((vars->env[i]) + length + 1);
}
