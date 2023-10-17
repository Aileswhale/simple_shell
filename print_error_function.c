#include "aileswhale.h"

/**
 * print_the_error - Prints an error message when a command is not found.
 * @counts: A counter that keeps track of
 * the number of commands run on the shell.
 * @av: The name of the program that is running the shell.
 * @cmd: The specific command that is not found.
 */

void print_the_error(char *av, int counts, char *cmd)
{
	print_string(av, 1);
	print_string(": ", 1);
	print_numbers(counts);
	print_string(": ", 1);
	print_string(cmd, 1);
}

/**
 * print_exec_error - Function for printing execution errors.
 * @av: The name of the program that is running the shell.
 * @counts: Keeps track of the number of commands that have been entered.
 * @tmp_cmd: The command that failed.
 */

void print_exec_error(char *av, int counts, char *tmp_cmd)
{
	print_the_error(av, counts, tmp_cmd);
	print_string(": ", 1);
	perror("");
	exit(1);
}

/**
 * print_simple_error - Executes and prints a simple error.
 * Return: Always void.
 */

void print_simple_error(void)
{
	perror("Error");
	exit(100);
}
