#include "aileswhale.h"

/**
 * *add_node_integer - Add a node in the beginning
 * @head: The pointer of the history list.
 * @string: The string received.
 *
 * Return: On success 1
 */

void *add_node_integer(history_t **head, char *string)
{

	history_t *new = malloc(sizeof(history_t));
	history_t *copy = *head;

	if (!new)
	{
		free_list_intinger(*head);
	}

	new->string = strdup(string);
	if (new->string == NULL)
	{
		free_list_intinger(*head);
	}

	new->next = NULL;
	if (!*head)
	{
		*head = new;
		return (new);
	}
	copy = *head;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
	return (new);
}

/**
 * free_list_iningert - free pointers associated with malloc
 * @head: pointer to the list
 *
 * Return:Number of elements in the list
 */

void free_list_intinger(history_t *head)
{
	history_t *del;

	if (!head)
		return;
	while (head)
	{
		del = head->next;
		free(head->string);

		free(head);
		head = del;
	}
	free(del);
}

/**
 * print_new_history - Displays the elements of a singular list.
 * @vars: A structure containing variables.
 * Return: The count of elements in the list.
 */

void print_new_history(vars_t *vars)
{
	history_t *temporary = vars->hstry;
	history_t *temporary2 = vars->hstry;
	int i = 0, z = 1;
	unsigned int count_number = 0;
	char *count;

	if (vars->array_tok[1] != NULL)
	{
		print_error_message(vars, ": Command not found: ");
		print_msg(vars->array_tok[1]);
		print_msg("\n");
		return;
	}
	else
	{
		while (temporary)
		{
			temporary = temporary->next;
			i++;
		}
		while (z < i)
		{
			count_number++;
			count = int_converter(count_number);
			print_msg(count);
			print_msg("  ");
			_print3(temporary2->string);
			temporary2 = temporary2->next;
			z++;
			free(count);
		}
		temporary2 = temporary2->next;
		vars->inverts = temporary2;
		free_list_intinger(temporary);
		free_list_intinger(temporary2);
		return;
	}
}
/**
 * _print3 - writes a string to standard output
 * @string: string to print
 *
 * Return: number of characters printed or -1 on failure
 */

ssize_t _print3(char *string)
{
	ssize_t i, length;

	for (i = 0; string[i]; i++)
		;

	length = write(1, string, i);
	if (length != i)
	{
		perror("Error");
		return (-1);
	}
	return (length);
}
/**
 *print_msg - print a string to standart output
 * @string: string to print.
 * Return: void
 */
void print_msg(char *string)
{
	long number, length;

	number = strlen(string);
	length = write(STDOUT_FILENO, string, number);
	if (length != number)

	{
		perror("error");
		exit(1);
	}
}
