#include "main.h"

/**
 * print_the_error - Prints a message error when a comand is not found.
 * @counts: A countser keeping track of the number of cmds run on the shell.
 * @av: The name of the program running the shell.
 * @cmd: The specific cmd not being found.
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
 * print_exec_error - Prints exec errors.
 * @av: The name of the program running the shell.
 * @counts: Keeps track of how many cmds have been entered.
 * @tmp_cmd: The cmd that filed.
 */

void print_exec_error(char *av, int counts, char *tmp_cmd)
{
	print_the_error(av, counts, tmp_cmd);
	print_string(": ", 1);
	perror("");
	exit(1);
}

/**
 * print_simple_error - Prints and exec simple error.
 * Return: always void.
 */
void print_simple_error(void)
{
	perror("Error");
	exit(100);
}
