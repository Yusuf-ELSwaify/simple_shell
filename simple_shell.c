#include "shell.h"
void make_process(char **args);

/* Global program name */
char *program_name;
/* Global counter */
int program_count;
/* Global return value */
int program_ret;

/**
 * main - a simple shell entry point
 * @argc: count of arguments
 * @argv: arguments
 * Return: Always 0.
 */
int main(int argc __attribute__((__unused__)), char *argv[])
{
	char *buffer = NULL, **args;
	int builtin_status;

	program_name = argv[0];
	program_count = 0, program_ret = 0;
	while (1)
	{
		++program_count;
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
			if (exit_code == 0)
				exit(program_ret);
			if (builtin_status == -1 && exit_code != -1)
				exit(exit_code);
			continue;
		}
		make_process(args);

		free(args);
		free(buffer);
	}

	exit(program_ret);
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
		if (errno == EACCES)
		{
			print_err(args[0], "Permission denied");
			program_ret = 126;
		}
		else
		{
			print_err(args[0], "not found");
			program_ret = 127;
		}
		return;
	}
	my_pid = fork();
	if (my_pid == -1)
	{
		print_err(args[0], "Error: unable to create a process (fork)");
		exit(EXIT_FAILURE);
	}
	if (my_pid == 0)
	{
		execve(path, args, environ);

		if (errno == EACCES)
		{
			print_err(args[0], "Permission denied");
			program_ret = 126;
		}

	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			program_ret = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			program_ret = WIFSIGNALED(status);
	}
	free(path);
}
