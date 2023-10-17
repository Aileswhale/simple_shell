#include "aileswhale.h"
/**
* check_if_matched - checks whether a character matches any in a string
 * @c: character to be checked
 * @string: string to be checked
 *
 * Return: 1 if there is a match, 0 if there is not
 */
unsigned int check_if_matched(char c, const char *string)
{
	unsigned int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (c == string[i])
			return (1);
	}
	return (0);
}

/**
 * new_string_token - A custom implementation of strtok
 * @string: The string that needs to be tokenized
 * @deli: The delimiter used for tokenization
 *
 * Description: This function tokenizes
 *	the provided string based on the specified delimiter.
 * Return: A pointer to the next token or NULL if there are no more tokens.
 */

char *new_string_token(char *string, const char *deli)
{
	static char *token_starts;
	static char *next_tokens;
	unsigned int i;

	if (string != NULL)
		next_tokens = string;
	token_starts = next_tokens;
	if (token_starts == NULL)
		return (NULL);
	for (i = 0; next_tokens[i] != '\0'; i++)
	{
		if (check_if_matched(next_tokens[i], deli) == 0)
			break;
	}
	if (next_tokens[i] == '\0' || next_tokens[i] == '#')
	{
		next_tokens = NULL;
		return (NULL);
	}
	token_starts = next_tokens + i;
	next_tokens = token_starts;
	for (i = 0; next_tokens[i] != '\0'; i++)
	{
		if (check_if_matched(next_tokens[i], deli) == 1)
			break;
	}
	if (next_tokens[i] == '\0')
		next_tokens = NULL;
	else
	{
		next_tokens[i] = '\0';
		next_tokens = next_tokens + i + 1;
		if (*next_tokens == '\0')
			next_tokens = NULL;
	}
	return (token_starts);
}

/**
 * path_build - Concatenates two strings to form a complete file path.
 * @dirctry: Represents a directory in the path.
 * @cmd: Represents a file in a directory of the path.
 *
 * Return: If successful, returns a string representing
 *	the complete command path; otherwise, returns NULL.
 */

char *path_build(char *dirctry, char *cmd)
{
	int i, j;
	int dir_len;
	int cmd_len;
	int length;
	char *built;

	if (dirctry == NULL || cmd == NULL)
		return (NULL);
	dir_len = strlen(dirctry) + 1;
	cmd_len = strlen(cmd) + 1;
	length = dir_len + cmd_len;

	built = malloc(sizeof(char) * length);
	if (built == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		for (j = 0; dirctry[j] != '\0'; j++, i++)
			built[i] = dirctry[j];
		built[i] = '/';
		i++;
		for (j = 0; cmd[j] != '\0'; j++, i++)
			built[i] = cmd[j];
	}
	built[--i] = '\0';
	return (built);
}
