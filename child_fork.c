#include "aileswhale.h"

/**
 * child_fork - Creates a child to execute another program.
 * @vars: A structure cointaining an array of pointers and a string.
 */
void child_fork(vars_t vars)
{
	pid_t id;
	int status, check;
	struct stat buff;
	char *tmp_cmd, *cmd;

	id = fork();
	if (id != 0)
		wait(&status);
	else
	{
		tmp_cmd = vars.array_tok[0];
		cmd = find_path(vars, vars.array_tok[0]);
		if (cmd == NULL)
		{

			check = stat(tmp_cmd, &buff);
			if (check == -1)
			{
				print_the_error(vars.argv[0], vars.vars_counter, tmp_cmd);
				print_string(": not found", 0);

				exit(100);
			}

			cmd = tmp_cmd;
		}
		vars.array_tok[0] = cmd;
		if (vars.array_tok[0] != NULL)
		{
			if (execve(vars.array_tok[0], vars.array_tok, vars.env) == -1)
				print_exec_error(vars.argv[0], vars.vars_counter, tmp_cmd);
		}
	}
}


/**
 * find_path - This function acts as a bridge for other functions to find
 *             the full path of a program.
 * @cmd: A common command such as ls, echo, pwd, etc.
 * Return: Returns a string containing the complete path of the program
 * upon success. If not successful, it returns NULL.
 * @vars: Structure that holds variables.
 */

char *find_path(vars_t vars, char *cmd)
{
	char *string = "PATH";
	char *constrct;
	char **token_path;
	int index, i;
	char *dir;

	index = env_path(vars, string);
	token_path = tokenise_path(vars, index, string);
	if (token_path == NULL)
		return (NULL);

	dir = search_dir(token_path, cmd);
	if (dir == NULL)
	{
		for (i = 0; token_path[i] != NULL; i++)
			free(token_path[i]);
		free(token_path);
		return (NULL);
	}
	constrct = path_build(dir, cmd);
	if (constrct == NULL)
	{
		for (i = 0; token_path[i] != NULL; i++)
			free(token_path[i]);
		free(token_path);
		return (NULL);
	}
	for (i = 0; token_path[i] != NULL; i++)
		free(token_path[i]);
	free(token_path);
	return (constrct);
}

/**
 * env_path - Identify the index of an environmental variable.
 * @vars: Structure containing the variables to be utilized.
 * @string: Environmental variable that requires identification.
 * Return: Returns the index of the environmental variable upon success;
 *	 otherwise, returns -1.
 */

int env_path(vars_t vars, char *string)
{
	int i, length, j;

	length = strlen(string);
	for (i = 0; vars.env[i] != NULL; i++)
	{
		for (j = 0; j < length; j++)
		{
			if (vars.env[i][j] != string[j])
				break;
		}
		if (j == length && vars.env[i][j] == '=')
			return (i);
	}
	return (-1);
}

/**
 * tokenise_path - Converts a string of a path into
 * an array of strings that represent the path directories.
 * @vars: A structure containing the variables to be used.
 * @index: The index of the path in the environment variables.
 * @string: The string to be separated and tokenized.
 *
 * Return: On success, a NULL-terminated array of strings
 * representing the path directories. Otherwise, it returns NULL.
 */

char **tokenise_path(vars_t vars, int index, char *string)
{
	char *env_var;
	int token_count = 0, length;
	char **token_path;
	const char *deli = ":\n";

	length = strlen(string);

	env_var = vars.env[index] + (length + 1);
	token_path = token_intrface(env_var, deli, token_count);
	if (token_path == NULL)
		return (NULL);

	return (token_path);
}

/**
 * search_dir - Examines directories stored in token_path
 * to locate a specific file known as cmd.
 * @token_path: Pointer to an array of strings containing
 * the paths found in the PATH environment variable.
 * @cmd: Represents a command, e.g., ls, /bin/ls, pwd, etc.
 *
 * Return: If successful, returns a string with the
 * directory containing the cmd file; otherwise, returns NULL.
 */

char *search_dir(char **token_path, char *cmd)
{
	int i, s;
	char *cwd, *buff;
	size_t size;
	struct stat stat_buff;

	buff = NULL;
	size = 0;
	cwd = getcwd(buff, size);
	if (cwd == NULL)
		return (NULL);
	if (cmd[0] == '/')
		cmd = cmd + 1;
	for (i = 0; token_path[i] != NULL; i++)
	{
		s = chdir(token_path[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(cmd, &stat_buff);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (token_path[i]);
		}
	}
	chdir(cwd);
	free(cwd);
	return (NULL);
}
