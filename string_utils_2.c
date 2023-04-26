#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @dest: the string add in it
 * @src: the string copy from it
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i++] != 0)
		;
	i--;
	while (src[j] != 0)
		dest[i++] = src[j++];
	return (dest);
}
/**
 * _strcmp - compare between two strings
 * @s1: 1st string
 * @s2: 2ns string
 * Return: the difference between the first difference two character
 * or 0 if no difference
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] - s2[i])
			return (s1[i] - s2[i]);
		i++;
	}

	if (s1[i])
		return (s1[i]);
	if (s2[i])
		return (-s2[i]);
	return (0);
}
/**
 * add_number - append the character number to the integer number
 * @dest: integer to add in it
 * @number: the character we need to add in the integer
 */
void add_number(unsigned int *dest, char number)
{
	*dest *= 10;
	*dest += number - '0';
}
/**
 * exit_atoi - turn string to integer
 * @s: pointer to array of character
 * Return: the number
 */
int exit_atoi(char *s)
{
	int i = 0;
	unsigned int number = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
			add_number(&number, s[i]);
		else
		{
			char *err = "Exit: Illegal number\n";

			write(STDERR_FILENO, err, _strlen(err));
			return (-1);
		}
		i++;
	}
	return (number);
}
