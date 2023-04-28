#include "shell.h"
/**
 * _itoa - turn an int to string.
 * @num: The integer.
 *
 * Return: The int string.
 */
char *_itoa(int num)
{
	int length = 0, temp = num;
	char *str;

	while (temp != 0)
	{
		length++;
		temp /= 10;
	}
	if (num < 0)
	{
		length++;
	}

	str = (char *)malloc((length + 1) * sizeof(char));
	if (str == NULL)
		print_err(NULL, ERR_MALLOC);
	str[length] = '\0';
	if (num < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	--length;
	do {
		str[length] = (num % 10) + '0';
		num /= 10;
		length--;
	} while (num > 0);

	return (str);
}
