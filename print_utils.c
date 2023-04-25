#include "shell.h"

/**
 * print - writes the string s and a trailing newline to stdout
 * @str: string to print
 * Return: 1 if success
 *          Otherwise -1 on fail
 */
int print(char *str)
{
	return (write(STDOUT_FILENO, str, _strlen(str)));
}
/**
 * print_err - writes the string s and a trailing newline to stdout
 * @str: err to print
 * Return: 1 if success
 *          Otherwise -1 on fail
 */
int print_err(char *str)
{
	return (write(STDERR_FILENO, str, _strlen(str)));
}
