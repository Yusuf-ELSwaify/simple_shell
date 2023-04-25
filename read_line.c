#include "shell.h"
/**
 * read_input - read input from user.
 * Return: splitted arguments
 */
char *read_input()
{
	char *buffer = NULL;
	size_t bufsize = 1024;

	if (getline(&buffer, &bufsize, stdin) == -1)
		free(buffer), exit(EXIT_SUCCESS);

	return (buffer);
}
