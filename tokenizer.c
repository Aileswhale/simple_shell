#include "main.h"

/**
 * tokenise - tokenizes a buff with a deli
 * @buff: buff to tokenize
 * @deli: deli to tokenize along
 *
 * Return: pointer to an array of pointers to the tokens
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
			tokens = _realloc(tokens, &m_count);
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
 * tokeniz - tokenizes a buff with a deli just use for for_child
 * @lines: buff to tokenize
 * @deli: deli to tokenize along
 * @token_counts: token count, size.
 * Return: pointer to an array of pointers to the tokens
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

/**
 * token_intrface - token interface
 * @lines: lines get to be tokenized
 * @deli: eny deli lie ; % " ", etc.
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
 * count_tokens - token's count
 * @lines: string.
 * @deli: deli
 * Return: token's count
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
