#include "shell.h"
/**
 * _getenv - searches for an environment variable by name.
 * @name: name of variable we search for.
 * Return: pointer to the value part of the environment variable.
 */
char *_getenv(const char *name)
{
	char **env = environ, *env_ptr, *name_ptr;

	while (*env != NULL)
	{
		env_ptr = *env;
		name_ptr = (char *)name;
		while (*env_ptr != '\0' && *name_ptr != '\0' && *env_ptr == *name_ptr)
		{
			if (*env_ptr == '=')
				break;
			env_ptr++;
			name_ptr++;
		}
		if (*env_ptr == '=' && *name_ptr == '\0')
			return (env_ptr + 1);
		env++;
	}
	return (NULL);
}
/**
 * concat_path - concatenate the command enviroment path with command
 * @path: the path of the command in enviroment variable
 * @file: the command
 * Return: the path concatenate the command
 */
char *concat_path(char *path, char *file)
{
	int i = 0, j = 0;
	char *result;

	result = malloc((_strlen(path) + _strlen(file) + 2) * sizeof(char));
	if (!result)
		return (NULL);
	*result = '\0';
	while (path[j])
		result[i++] = path[j++];
	result[i++] = '/';
	j = 0;
	while (file[j])
		result[i++] = file[j++];
	result[i] = '\0';
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
		return (_strdup(file));
	path = _getenv("PATH");
	path = _strdup(path);
	tokens = split_string(path, ":");
	while (tokens[i])
	{
		command = concat_path(tokens[i], file);
		if (stat(command, &st) == 0)
		{
			free(tokens);
			free(path);
			return (command);
		}
		i++;
		free(command);
	}
	free(path);
	free(tokens);
	return (NULL);
}
