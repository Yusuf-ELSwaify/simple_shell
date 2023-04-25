#include "shell.h"
#define DELIMITER " \n\t"
/**
 * split_input - split the line by delimeters.
 * @line: line to split
 * Return: splitted arguments
 */
char **split_input(char *line)
{
	int num_args = 0;
	char **args = malloc(MAX_TOKENS * sizeof(char *));

	if (args == NULL)
		perror(ERR_MALLOC), exit(EXIT_FAILURE);
	args[num_args] = strtok(line, DELIMITER);
	while (args[num_args] && num_args < (MAX_TOKENS - 1))
		args[++num_args] = strtok(NULL, DELIMITER);

	args[num_args] = NULL;
	return (args);
}
#undef DELIMITER
