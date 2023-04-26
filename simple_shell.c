#include "shell.h"
/**
 * main - a simple shell entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	char *buffer = NULL, *path, **args;

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
		path = _which(args[0]);

		my_pid = fork();
		if (my_pid == -1)
		{
			print_err(args[0], "Error: unable to create a process (fork)\n");
			exit(EXIT_FAILURE);
		}
		if (my_pid == 0)
		{
			int execve_status;

			if (path == NULL)
				execve_status = execve(args[0], args, NULL);
			else
				execve_status = execve(path, args, NULL);

			if (execve_status == -1)
				print_err(args[0], "Error: command not found\n");
		}
		else
			wait(NULL);
		free(path);
		free(args);
		free(buffer);
	}

	return (0);
}
