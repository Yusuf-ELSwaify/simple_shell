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
char *concat_path(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int src_len = _strlen(src);
	char *result = malloc(dest_len + src_len + 2);

	if (!result)
		return (NULL);
	_strcpy(result, dest);
	strcat(result, "/");
	strcat(result, src);
	return (result);
}

char *_which(char *filename)
{
	unsigned int i = 0;
	char **tokens, *path, *command;
	struct stat st;

	if (stat(filename, &st) == 0)
		return (NULL);
	path = _getenv("PATH");
	tokens = split_string(path, ":");
	while (tokens[i])
	{
		command = concat_path(tokens[i], filename);
		if (stat(command, &st) == 0)
			return (command);
		i++;
	}
}
