#include "shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: the old pointer
 * @old_size: memory old size
 * @new_size: the new size to be allocated
 * Return: a pointer to a newly allocated space in memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i = -1;
	void *new_ptr;

	if (!new_size && ptr)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr && new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
	{
		free(ptr);
		return (NULL);
	}
	while (ptr && ++i < old_size)
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	free(ptr);
	return (new_ptr);
}
/**
 * _getline - read a line from a file or standard input
 * @lineptr: ptr to point to the input
 * @n: buffer size
 * @fd: the file descriptor
 * Return: the size of string
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *fd)
{
	static ssize_t count;
	int c = 0, r, ret;
	char *buffer = NULL;

	if (count != 0)
		return (-1);
	fflush(fd);
	if (lineptr == NULL || n == NULL)
		return (-1);
	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(BUFFER_SIZE);
		*n = BUFFER_SIZE;
	}
	buffer = *lineptr;
	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && count == 0))
			return (-1);
		if (r == 0 && count != 0 && count++)
			break;
		buffer[count] = c;
		count++;
		if (count == (ssize_t)*n)
		{
			*n *= 2;
			buffer = _realloc(*lineptr, count, *n);
			if (buffer == NULL)
				return (-1);
			*lineptr = buffer;
		}
	}
	ret = count;
	if (count == 0)
		return (-1);
	buffer[count] = '\0';
	if (r != 0)
		count = 0;
	return (ret);
}
