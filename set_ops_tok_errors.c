#include "monty.h"

/**
 * set_ops_tok_errors - Sets last element of ops_tok to be an error code.
 * @error_code: Integer to store as a string in ops_tok.
 */
void set_ops_tok_errors(int error_code)
{
	int tok_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_tok = NULL;

	tok_len = token_arr_len();
	new_tok = malloc(sizeof(char *) * (tok_len + 2));
	if (!ops_tok)
	{
		malloc_error();
		return;
	}
	while (i < tok_len)
	{
		new_tok[i] = ops_tok[i];
		i++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_tok);
		malloc_error();
		return;
	}
	new_tok[i++] = exit_str;
	new_tok[i] = NULL;
	free(ops_tok);
	ops_tok = new_toks;
}
