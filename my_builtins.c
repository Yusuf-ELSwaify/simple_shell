#include "shell.h"
/**
 * _abort - exits the shell
 * @buffer: input to free
 * Return: -1
 */
int _abort()
{
	return (-1);
}

/**
 * shell_env - prints environment
 * Return: 0
 */
int shell_env()
{
	unsigned int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
/**
 * handle_builtins - look for the command function
 * @command: command
 * Return: (handled) 1 is returned
 *		  otherwise 0
 */
int handle_builtins(char *command)
{
	unsigned int i = 0;

	cmd_t list[] = {
		{"exit", _abort},
		{"env", shell_env},
		{0, 0}
	};

	while ((list + i)->cmd)
	{
		if (_strcmp(command, (list + i)->cmd) == 0)
			return ((list + i)->func());
		i++;
	}
	return (0);
}
