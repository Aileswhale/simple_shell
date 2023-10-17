#include "aileswhale.h"
/**
 * new_help_builtin_cmd - help builtin command
 * @vars: if the command matches a builtin name
 *	the text files is sent to standard output
 * Return: 0 if sucess
 */

void new_help_builtin_cmd(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (vars->array_tok[1] == NULL)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/help";
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
		return;
	}
	else
		new_help_help_builtin(vars);
}

/**
 * new_help_help_builtin - help builtin command help
 * @vars: if command matches a builtin name
 *	the text files is sent to standard output
 * Return: 0 if sucess
 */
void new_help_help_builtin(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "help") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/help_help";
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
		new_help_exit_builtin(vars);
}

/**
 * new_help_exit_builtin - help builtin command exit
 * @vars: if command matches a builtin name
 *	the text files is sent to standard output
 * Return: 0 if sucess
 */
void new_help_exit_builtin(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "exit") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/exit";
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
		new_help_cd_builtin(vars);
}
/**
 * new_help_cd_builtin - help builtin command cd
 * @vars: if the command matches a builtin name,
 *	the text files is sent to standard output
 * Return: 0 if sucess
 */
void new_help_cd_builtin(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "cd") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/cd";
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
		new_help_env_builtin(vars);
}
/**
 * new_help_env_builtin - help builtin command env
 * @vars: if the command matches a builtin name
 *	the text files is sent to standard output
 * Return: 0 if sucess
 */
void new_help_env_builtin(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "env") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/env";
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
		new_help_history_cmd(vars);
}
