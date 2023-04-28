#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define PROMPT "$ "
#define BUFFER_SIZE 1024
#define MAX_TOKENS 64
#define SPACES " \n\t\r\f\v"

#define ERR_MALLOC "Error: unable to allocate space"

extern char **environ;


/* Global program name */
extern char *program_name;
/* Global counter */
extern int program_count;
/* Global return value */
extern int program_ret;

/**
 * struct command_type - Manage the commands function
 * @cmd: the command line on string form
 * @func: the associated function
 */
typedef struct command_type
{
	char *cmd;
	int (*func)();
} cmd_t;

/*string utility functions */
char **split_string(char *str, char *delimeters);
char *_strchr(char *s, char c);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int exit_atoi(char *s);
char *_itoa(int num);

/*read utility functions */
char *read_input();
int is_empty(char *buffer);
char **split_input(char *line);

/*print utility functions */
int print(char *str);
int print_err(char *err_reason, char *str);

/*enviroment utility functions */
char *_which(char *file);

/*my builtins*/
int _abort(void);
int handle_builtins(char *command);

/*read_line function*/
ssize_t _getline(char **lineptr, size_t *n, FILE *fd);

#endif /* SHELL_H */
