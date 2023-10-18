#include "aileswhale.h"

/**
 * token_intrface -the token interface
 * @lines:the lines get to be tokenized
 * @deli: eny delimiter lie ; % " ", etc.
 * @token_counts: token counter.
 * Return: tokens
 **/
char **token_intrface(char *lines, const char *deli, int token_counts)
{
	vars_t vars;

	token_counts = count_tokens(lines, deli);
	if (token_counts == -1)
	{
		free(lines);
		return (NULL);
	}
	vars.array_tok = tokeniz(token_counts, lines, deli);
	if (vars.array_tok == NULL)
	{
		free(lines);
		return (NULL);
	}

	return (vars.array_tok);
}

/**
 * count_tokens -the token count
 * @lines: string.
 * @deli: delimiter
 * Return:the token count
 **/
int count_tokens(char *lines, const char *deli)
{
	char *string;
	char *token;
	int i;

	string = strdup(lines);
	if (string == NULL)
		return (-1);
	token = new_string_token(string, deli);
	for (i = 0; token != NULL; i++)
		token = new_string_token(NULL, deli);
	free(string);
	return (i);
}

/**
 * tokenise - Splits a buffer into tokens using a delimiter
 * @buff: Buffer to be tokenized
 * @deli: Delimiter to use for tokenization
 *
 * Return: A pointer to an array of pointers pointing to the tokens
 */
char **tokenise(char *buff, char *deli)
{
	char **tokens = NULL;
	size_t i = 0, m_count = 10;

	if (buff == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * m_count);
	if (tokens == NULL)
	{
		perror("Error");
		return (NULL);
	}
	while ((tokens[i] = new_string_token(buff, deli)) != NULL)
	{
		i++;
		if (i == m_count)
		{
			tokens = reallocate(tokens, &m_count);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		buff = NULL;
	}
	return (tokens);
}


/**
 * tokeniz - Splits a buff using a deli, specifically for for_child usage
 * @lines: Buffer to be tokenized
 * @deli: Delimiter to be used for tokenization
 * @token_counts: Count and size of the tokens
 *
 * Return: Pointer to an array of pointers that point to the tokens
 */

char **tokeniz(int token_counts, char *lines, const char *deli)
{
	int i;
	char **buff;
	char *token;
	char *lines_cp;

	lines_cp = strdup(lines);
	buff = malloc(sizeof(char *) * (token_counts + 1));
	if (buff == NULL)
		return (NULL);
	token = new_string_token(lines_cp, deli);
	for (i = 0; token != NULL; i++)
	{
		buff[i] = strdup(token);
		token = new_string_token(NULL, deli);
	}
	buff[i] = NULL;
	free(lines_cp);
	return (buff);
}
