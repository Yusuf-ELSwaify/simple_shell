#include "shell.h"

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
	args[num_args] = strtok(line, SPACES);
	while (args[num_args] && num_args < (MAX_TOKENS - 1))
		args[++num_args] = strtok(NULL, SPACES);

	args[num_args] = NULL;
	return (args);
}
/**
 * _strlen - get the length of a string
 * @str: pointer to array of characters
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _strchr - locates a character in a string
 * @s: string to search in
 * @c: character to search for
 * Return: pointer to the first occurence of c in s
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}
