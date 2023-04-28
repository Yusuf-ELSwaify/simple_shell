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

	while (dest[i] != 0)
		i++;
	while (src[j] != 0)
		dest[i++] = src[j++];
	dest[i] = '\0';
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
 * _atoi - turn string to integer
 * @s: pointer to array of character
 * Return: the number
 */
int _atoi(char *s)
{
	int i = 0, sign = 1;
	unsigned int number = 0;

	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = -sign;
		}
		else if (s[i] >= '0' && s[i] <= '9')
			add_number(&number, s[i]);
		else if (number > 0)
			break;
		i++;
	}
	return (number * sign);
}
/**
 * exit_atoi - turn string to integer
 * @s: pointer to array of character
 * Return: the number
 */
int exit_atoi(char *s)
{
	int i = 0;

	if (s == NULL || s[i] == '\0')
		return (0);
		
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
		{
			char *err_str;
			int len;

			len = 16 + _strlen(s);
			err_str = malloc(sizeof(char) * (len + 1));
			err_str[len] = '\0';
			strcpy(err_str, "Illegal number: ");
			_strcat(err_str, s);
			print_err(_strdup("exit"), err_str);
			free(err_str);
			program_ret = 2;
			return (-1);
		}
		i++;
	}
	return (_atoi(s));
}
