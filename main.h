#ifndef _SHELL_MAIN_
#define _SHELL_MAIN_
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
 * @string: string
 * @counter:the number of inputs
 * @next: Next element
 */

typedef struct history
{
	char *string;
	int count_number;
	struct history *next;

} history_t;


/**
 * struct variables - a structure of various variables
 * @array_tokens:an array of tokens(arguments)
 * @buffer: buffer of command
 * @status: Manage exit status
 * @argv: retrieves arguments at opening of shell
 * @counter: counts commands entered
 * @env: holds enviroment information
 * @commands: have commands.
 * @history: structure data for history
 * @invert: structure data for inversion
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
 * struct builtins - structure for the builtin functions
 * @names: contains names of builtin command
 * @f: function for the corresponding builtin
 */
typedef struct builtins
{
	char *names;
	void (*f)(vars_t *);
} builtins_t;

/*** String operations and manipulation***/
ssize_t _print(char *string);
void print_string(char *string, int newline);
int _putchar(char c);
int print_numbers(int n);

/*** BUILTINGS PROTOTYPES ****/
void (*builtin_cmd(vars_t *vars))(vars_t *vars);
void exit_program(vars_t *vars);
void print_the_enviroment(vars_t *vars);
void create_new_env(vars_t *vars);
void remove_new_env(vars_t *vars);
void new_help_builtin_cmd(vars_t *vars);
void new_the_cd(vars_t *vars);

/** functions related to tokenizer **/
char **tokenise(char *buff, char *deli);
unsigned int check_if_matched(char c, const char *string);
char **_realloc(char **pointer, size_t *sizes);
char *new_string_token(char *string, const char *deli);

/** second tokenizer**/
char **tokeniz(int token_counts, char *lines, const char *deli);
char **token_intrface(char *lines, const char *deli, int token_counts);
int count_tokens(char *lines, const char *deli);
/** functions related ask external shell, ask the path**/
void check_for_path(vars_t *vars);

/** function to handle error messages, used to help exit function*/
void _print_error(char *string);
void print_error_message(vars_t *vars, char *message);
char *int_converter(unsigned int counter);

/** function to help exit builting*/
int _atoi(char *str);


/*functions to get enviroment*/
char **make_shell_enviroment(char **env);
void free_shell_env(char **env);

/**New_help functions**/
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

/** FUNCTIONS RELETETD SETENV AND UNSETENV**/
void new_setenv(vars_t *vars);
void add_keys(vars_t *vars);
char *add_values(char *keys, char *values);
char **find_keys(char **env, char *keys);
void setenv_cd(char **args, vars_t *vars);
void chdir_to_enviroment(vars_t *vars, char *string);

/** ask the path **/
void child_fork(vars_t vars);
char *find_path(vars_t vars, char *cmd);
int env_path(vars_t vars, char *string);
char **tokenise_path(vars_t vars, int index, char *string);
char *search_dir(char **token_path, char *cmd);
char *path_build(char *dirctry, char *cmd);

/** More handle error messages**/
void print_the_error(char *av, int counts, char *cmd);
void print_exec_error(char *av, int counts, char *tmp_cmd);
void print_simple_error(void);
void print_cdir_1(vars_t *vars);
void print_cdir_2(vars_t *vars);

/**history build function**/
void print_new_history(vars_t *vars);
void *add_node_integer(history_t **head, char *string);
void free_list_intinger(history_t *head);
ssize_t _print3(char *string);
void print_msg(char *string);
/** handles signals**/

void end_of_file(char *buffer);
unsigned int signal_flag;

#endif /* _SHELL_MAIN_ */
