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
