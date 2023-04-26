#include "shell.h"
/**
 * _getenv - searches for an environment variable by name.
 * @name: name of variable we search for.
 * Return: pointer to the value part of the environment variable.
 */
char *_getenv(const char *name)
{
	unsigned int i = 0;
	char **env = environ, *env_ptr, *name_ptr;

	while (*env != NULL)
	{
		env_ptr = _strdup(*env);
		name_ptr = (char *)name;
		while (*env_ptr != '\0' && *name_ptr != '\0' && *env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
			{
				free(env_ptr);
				break;
			}
			env_ptr++;
			name_ptr++;
		}
		if (*env_ptr == '=')
			if (*name_ptr == '\0')
				return (env_ptr + 1);
		env++;
	}
	return (NULL);
}
/**
 * concat_path - concatenate the command enviroment path with command
 * @path: the path of the command in enviroment variable
 * @command: the command
 * Return: the path concatenate the command
 */
char *concat_path(char *path, char *command)
{
	int path_len = _strlen(path);
	int command_len = _strlen(command);
	char *result = malloc(path_len + command_len + 2);

	if (!result)
		return (NULL);
	_strcpy(result, path);
	_strcat(result, "/");
	_strcat(result, command);
	return (result);
}
/**
 * _which - get the full path of any file
 * @file: file to get path
 * Return: the full path
 */
char *_which(char *file)
{
	unsigned int i = 0;
	char **tokens, *path, *command;
	struct stat st;

	if (stat(file, &st) == 0)
		return (NULL);
	path = _getenv("PATH");
	tokens = split_string(path, ":");
	while (tokens[i])
	{
		command = concat_path(tokens[i], file);
		if (stat(command, &st) == 0)
			return (command);
		i++;
	}
}
