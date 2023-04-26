#include "shell.h"
void make_process(char **args);
/**
 * main - a simple shell entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL, **args;
	int builtin_status;

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
		builtin_status = handle_builtins(args[0]);
		if (builtin_status == -1 || builtin_status == 1)
		{
			int exit_code = exit_atoi(args[1]);

			free(buffer);
			free(args);
			if (builtin_status == -1 && exit_code != -1)
				exit(exit_code);
			continue;
		}
		make_process(args);

		free(args);
		free(buffer);
	}

	return (0);
}
/**
 * make_process - create child proccess
 * @args: proccess arguments
 */
void make_process(char **args)
{
	pid_t my_pid;
	int status;
	char *path = _which(args[0]);

	if (path == NULL)
	{
		print_err(args[0], "Error: command not found\n");
		return;
	}
	my_pid = fork();
	if (my_pid == -1)
	{
		print_err(args[0], "Error: unable to create a process (fork)\n");
		exit(EXIT_FAILURE);
	}
	if (my_pid == 0)
	{
		int execve_status = execve(path, args, NULL);

		if (execve_status == -1)
			print_err(args[0], "Error: command not found\n"), exit(EXIT_FAILURE);
	}
	else
		waitpid(my_pid, &status, 0);
	free(path);
}
