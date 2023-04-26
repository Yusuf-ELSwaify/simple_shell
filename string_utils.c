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
/**
 * _strcpy - copy string characters to another string
 * @dest: pointer to array of characters copy in it
 * @src: array we will copy from it
 * Return: the pointer of the destination array
 */
char *_strcpy(char *dest, char *src)
{
	int i = -1;

	do
	{
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}
/**
 * _strdup - clone a string
 * @str: the given string
 *
 * Return: (Success) a pointer to the clone
 * ------- (Fail) return a null pointer
 */
char *_strdup(char *str)
{
	char *clone;

	if (str == NULL)
		return (NULL);
	clone = malloc(_strlen(str) + 1);
	if (clone == NULL)
		return (NULL);
	_strcpy(clone, str);
	return (clone);
}