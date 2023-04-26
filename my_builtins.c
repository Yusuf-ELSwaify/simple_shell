#include "shell.h"
/**
 * _abort - exits the shell
 * @buffer: input to free
 * Return: -1
 */
int _abort(char *buffer __attribute__((unused)))
{
	return (-1);
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
		{0, 0}
	};

	while ((list + i)->cmd)
	{
		if (_strcmp(command, (list + i)->cmd) == 0)
			return ((list + i)->func(command));
		i++;
	}
	return (0);
}
