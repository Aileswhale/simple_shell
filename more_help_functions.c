#include "main.h"
/**
 * new_help_history_cmd - help builtin command history
 * @vars: if command matches a builtin name, text files is sent to stdout
 * Return: 0 if sucess
 */
void new_help_history_cmd(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "history") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/history";
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
		new_help_unalias_builtin(vars);
}
/**
 * new_help_unalias_builtin - help builtin command unalias
 * @vars: if command matches a builtin name, text files is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unalias_builtin(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "unalias") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/unalias";
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
		new_help_unset_builtin(vars);
}
/**
 * new_help_unset_builtin - help builtin command unset
 * @vars: if command matches a builtin name, text files is sent to stdout
 * Return: 0 if sucess
 */
void new_help_unset_builtin(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "unset") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/unset";
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
		new_help_builtin_unsetenv(vars);
}
/**
 * new_help_builtin_unsetenv - help builtin command unsetenv
 * @vars: if command matches a builtin name, text files is sent to stdout
 * Return: 0 if sucess
 */
void new_help_builtin_unsetenv(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "unsetenv") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/unsetenv";
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
		new_help_builtin_setenv(vars);
}
/**
 * new_help_builtin_setenv - help builtin command setenv
 * @vars: if command matches a builtin name, text files is sent to stdout
 * Return: 0 if sucess
 */
void new_help_builtin_setenv(vars_t *vars)
{
	char *files;
	int f_d, r;
	char *s;

	if (strcmp(vars->array_tok[1], "setenv") == 0)
	{
		files = "/home/shell_test/shelltestenviroment/helpfiless/setenv";
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
		new_help_alias_builtin(vars);
}
