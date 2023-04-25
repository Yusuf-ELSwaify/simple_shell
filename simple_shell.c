#include "shell.h"
/**
 * main - a simple shell entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	char *buffer = NULL, **args;

	while (1)
	{
		print(PROMPT);
		buffer = read_input();
		if (is_empty(buffer))
		{
			free(buffer);
			continue;
		}
		args = split_input(buffer);

		my_pid = fork();
		if (my_pid == -1)
		{
			//perror();
			print_err(args[0], "Error: unable to create a process (fork)\n");
			exit(EXIT_FAILURE);
		}
		if (my_pid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				// perror("Error: command not found\n");
				print_err(args[0], "Error: command not found\n");
		}
		else
			wait(NULL);
		free(args);
		free(buffer);
	}

	return (0);
}
