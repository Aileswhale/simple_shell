#include "aileswhale.h"

/**
 * signal_handler - manage the ^C signal interuption
 * @unused: unused variable (required for the signal function prototype)
 *
 * Return: void
 */
static void signal_handler(int unused)
{
	(void)unused;
	if (signal_flag == 0)
		write(1, "\n$ ", 2);
	else
		write(1, "\n", 2);
}
/**
 * main - the main function for the shell
 * @argc:the number of arguments passed to main, unused
 * @argv:the array of arguments passed to main
 * @environ:the array of environ variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environ)
{
	size_t length_buffer = 0;
	unsigned int i;
	unsigned int pipe = 0;

	vars_t vars = {NULL, NULL, 0, NULL, 0, NULL, NULL, NULL, NULL};

	vars.argv = argv;
	vars.env = make_shell_enviroment(environ);

	signal(SIGINT, signal_handler);

	if (!isatty(STDIN_FILENO))
		pipe = 1;
	if (pipe == 0)
		write(1, "$ ", 2);
	signal_flag = 0;

	while (getline(&(vars.buff), &length_buffer, stdin) != -1)
	{
		vars.vars_counter++;
		vars.cmd = tokenise(vars.buff, ";");
		for (i = 0; vars.cmd && vars.cmd[i] != NULL; i++)
		{
			vars.array_tok = tokenise(vars.cmd[i], " \t\r\n\a");
			if (vars.array_tok && vars.array_tok[0])
				if (builtin_cmd(&vars) == NULL)
				{
					child_fork(vars);
				}
			free(vars.array_tok);
		}
		free(vars.buff);
		free(vars.cmd);
		if (pipe == 0)
			write(1, "$ ", 2);
		vars.buff = NULL;
	}
	free_shell_env(vars.env);
	free(vars.buff);
	exit(vars.status);
}
