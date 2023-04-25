#include "shell.h"

/**
 * print - writes the string str
 * @str: string to print
 * Return: 1 if success
 *          Otherwise -1 on fail
 */
int print(char *str)
{
	if (isatty(STDIN_FILENO))
		return (write(STDOUT_FILENO, str, _strlen(str)));
	return (0);
}

/**
 * print_err - writes the err str
 * @err_reason: what caused the error
 * @str: err to print
 * Return: 1 if success
 *          Otherwise -1 on fail
 */
int print_err(char *err_reason, char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
	perror(err_reason);
	return -1;
}
