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
	char *program_count_str = NULL;

	program_count_str = _itoa(program_count);
	if (!program_count_str)
		return (-1);

	write(STDERR_FILENO, program_name, _strlen(program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, program_count_str, _strlen(program_count_str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_reason, _strlen(err_reason));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, _strlen(str));
	write(STDERR_FILENO, "\n", 2);
	free(program_count_str);
	return (-1);
}
