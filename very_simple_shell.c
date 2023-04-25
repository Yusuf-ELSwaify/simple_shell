#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "$ "
#define DELIMITER " \n\t"
#define MAX_TOKENS 64
/**
 * split_line - split the line by delimeters.
 * @line: line to split
 * @args: array to put in it splitted strings
 * Return: number of args
 */
int split_line(char *line, char **args)
{
	int num_args = 0;

	args[num_args] = strtok(line, DELIMITER);
	while (args[num_args] && num_args < (MAX_TOKENS - 1))
	{
		args[++num_args] = strtok(NULL, DELIMITER);
	}
	args[num_args] = NULL;
	return (num_args);
}
/**
 * main - executes the command ls -l /tmp in 5 different child processes.
 * Each child should be created by the same process (the father).
 * (Wait for a child to exit before creating a new child).
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	size_t bufsize = 1024;
	char *buffer = NULL, **args;

	args = malloc(MAX_TOKENS * sizeof(*args));
	if (args == NULL)
		return (-1);
	while (1)
	{
		printf(PROMPT);
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			break;
		}
		if (split_line(buffer, args) == 0)
			return (-1);
		my_pid = fork();
		if (my_pid == -1)
		{
			perror("Error: unable to create a process (fork)\n");
			exit(EXIT_FAILURE);
		}
		if (my_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("Error: command not found\n");
			}
		}
		else
			wait(NULL);
	}
	free(args);
	return (0);
}
