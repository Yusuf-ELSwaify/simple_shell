#include "shell.h"
/**
 * read_input - read input from user.
 * Return: user input
 */
char *read_input()
{
	char *buffer = NULL;
	size_t bufsize = 1024;

	if (read_line(&buffer, &bufsize, fileno(stdin)) == -1)
	{
		print("\n");
		free(buffer);
		_exit(EXIT_SUCCESS);
	}
	return (buffer);
}
/**
 * is_empty - check if the string is empty.
 * @buffer: string to check
 * Return: 1 if empty
 *				Otherwise 0
 */
int is_empty(char *buffer)
{
	char *temp = buffer;

	while (*temp != '\0')
	{
		if (_strchr(SPACES, *temp) == NULL)
			return (0);
		temp++;
	}
	return (1);
}
/**
 * split_input - split the line by spaces.
 * @line: line to split
 * Return: splitted arguments
 */
char **split_input(char *line)
{
	return (split_string(line, SPACES));
}
