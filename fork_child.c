#include "main.h"

/**
 * child_fork - Creates a child in  order to execute another program.
 * @vars: A structure cointaining a array of pointers and a string.
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
			/* Looking for file in current dir */
			check = stat(tmp_cmd, &buff);
			if (check == -1)
			{
				print_the_error(vars.argv[0], vars.vars_counter, tmp_cmd);
				print_string(": not found", 0);

				exit(100);
			}
			/* file exist in cwd or has full path */
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
 * find_path - Acts as an interface for functions that will be able
 * to find the full path of a program.
 * @cmd: A common cmd such as ls, echo, pwd, etc..
 * Return: On success a string with the full path of the program.
 * @vars: structure with variables.
 * oterwise returns NULL.
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
 * env_path - Finds the index of an environmental variable.
 * @vars: structure with variables will be used
 * @string: Environmental variable that needs to be found.
 * Return: Upon success returns the inde of the environmental variale
 * otherwise returns -1.
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
 * tokenise_path - Separates a string of path as an array of
 * strings containing the path directories.
 * @vars: structure with variables will be used
 * @index: index of the path in the environment variables.
 * @string: string to separate and tokenize
 * Return: On success a NLL terminated array of string.
 * otherwise returns NULL.
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
 * search_dir - Looks through directories stored in token_path
 * for a specific file aka cmd.
 * @token_path: A pointer to array of strings containings de paths
 * contained in the PATH environment variable.
 * @cmd: Represents a cmd. i.e. ls, /bin/ls, pwd, etc.
 *
 * Return: On success a string with the dir containing the
 * cmd file. Otherwise NULL.
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
