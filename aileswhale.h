#ifndef AILESWHALE_H
#define AILESWHALE_H
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct history - A structure for each command read
 * @string: A string containing the command
 * @count_number: The number of inputs
 * @next: Pointer to the next element in the history
 */

typedef struct history
{
	char *string;
	int count_number;
	struct history *next;

} history_t;


/**
 * struct variables - A composite structure containing diverse variables.
 * @array_tok: An array of tokens representing arguments.
 * @buff: A command buffer used for storage.
 * @status:  Responsible for managing the exit status of commands.
 * @argv: Stores the arguments provided when the shell is launched.
 * @vars_counter: A counter that keeps track
 * of the number of entered commands.
 * @env: Holds environmental information.
 * @cmd: Used to store various commands.
 * @hstry: A data structure for managing command history.
 * @inverts: A data structure used for managing inversions.
 */

typedef struct variables
{
	char **array_tok;
	char *buff;
	int status;
	char **argv;
	int vars_counter;
	char **env;
	char **cmd;
	history_t *hstry;
	history_t *inverts;

} vars_t;

/**
 * struct builtins - A structure designed to manage builtin functions.
 * @names: Stores the names of builtin commands.
 * @f: Associates each builtin command with its corresponding function.
 */

typedef struct builtins
{
	char *names;
	void (*f)(vars_t *);
} builtins_t;

/*** String handling and manipulation functions ***/
ssize_t _print(char *string);
void print_string(char *string, int newline);
int _putchar(char c);
int print_numbers(int n);

/*** BUILT-IN FUNCTION PROTOTYPES ***/
void (*builtin_cmd(vars_t *vars))(vars_t *vars);
void exit_program(vars_t *vars);
void print_the_enviroment(vars_t *vars);
void create_new_env(vars_t *vars);
void remove_new_env(vars_t *vars);
void new_help_builtin_cmd(vars_t *vars);
void new_the_cd(vars_t *vars);

/*** TOKENIZER-RELATED FUNCTIONS ***/
char **tokenise(char *buff, char *deli);
unsigned int check_if_matched(char c, const char *string);
char **_realloc(char **pointer, size_t *sizes);
char *new_string_token(char *string, const char *deli);


/*** STRING TOKENIZER FUNCTIONS ***/
char **tokeniz(int token_counts, char *lines, const char *deli);
char **token_intrface(char *lines, const char *deli, int token_counts);
int count_tokens(char *lines, const char *deli);

/*** SHELL INTERACTION AND PATH FUNCTIONS ***/
void check_for_path(vars_t *vars);

/*** ERROR MESSAGE HANDLING FUNCTION, UTILIZED TO ASSIST EXIT FUNCTION ***/
void _print_error(char *string);
void print_error_message(vars_t *vars, char *message);
char *int_converter(unsigned int counter);

/*** FUNCTION TO ASSIST EXIT BUILTIN COMMAND ***/
int _atoi(char *str);

/*** FUNCTIONS TO RETRIEVE ENVIRONMENT VARIABLES ***/
char **make_shell_enviroment(char **env);
void free_shell_env(char **env);

/*** FUNCTIONS FOR PROVIDING HELP INFORMATION ***/
void new_help_exit_builtin(vars_t *vars);
void new_help_help_builtin(vars_t *vars);
void new_help_cd_builtin(vars_t *vars);
void new_help_env_builtin(vars_t *vars);
void new_help_history_cmd(vars_t *vars);
void new_help_unalias_builtin(vars_t *vars);
void new_help_unset_builtin(vars_t *vars);
void new_help_builtin_unsetenv(vars_t *vars);
void new_help_builtin_setenv(vars_t *vars);
void new_help_alias_builtin(vars_t *vars);
void new_help_else_builtin(vars_t *vars);

/*** FUNCTIONS RELATED TO SETENV AND UNSETENV BUILT-INS ***/
void new_setenv(vars_t *vars);
void add_keys(vars_t *vars);
char *add_values(char *keys, char *values);
char **find_keys(char **env, char *keys);
void setenv_cd(char **args, vars_t *vars);
void chdir_to_enviroment(vars_t *vars, char *string);

/** Functions Related to Finding the Executable Path **/
void child_fork(vars_t vars);
char *find_path(vars_t vars, char *cmd);
int env_path(vars_t vars, char *string);
char **tokenise_path(vars_t vars, int index, char *string);
char *search_dir(char **token_path, char *cmd);
char *path_build(char *dirctry, char *cmd);

/** More Functions for Handling Error Messages **/
void print_the_error(char *av, int counts, char *cmd);
void print_exec_error(char *av, int counts, char *tmp_cmd);
void print_simple_error(void);
void print_cdir_1(vars_t *vars);
void print_cdir_2(vars_t *vars);

/** Functions for Building and Managing Command History **/
void print_new_history(vars_t *vars);
void *add_node_integer(history_t **head, char *string);
void free_list_intinger(history_t *head);
ssize_t _print3(char *string);
void print_msg(char *string);

/** Signal Handling Functions **/
void end_of_file(char *buffer);
unsigned int signal_flag;

#endif /*_AILESWHALE_*/
