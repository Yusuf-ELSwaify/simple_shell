#include "shell.h"

/**
 * split_string - split the line by delimeters.
 * @str: string to split
 * @delimeters: delimeters you need to split your string by
 * Return: splitted strings
 */
char **split_string(char *str, char *delimeters)
{
	int num_args = 0;
	char **args = malloc(MAX_TOKENS * sizeof(char *));

	if (args == NULL)
	{
		print_err(NULL, ERR_MALLOC);
		exit(EXIT_FAILURE);
	}

	args[num_args] = strtok(str, delimeters);
	while (args[num_args] && num_args < (MAX_TOKENS - 1))
		args[++num_args] = strtok(NULL, delimeters);

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
