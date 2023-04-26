#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "$ "
#define MAX_TOKENS 64
#define SPACES " \n\t\r\f\v"

#define ERR_MALLOC "Error: unable to allocate space\n"

extern char **environ;

/*string utility functions */
char **split_string(char *str, char *delimeters);
char *_strchr(char *s, char c);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);

/*read utility functions */
char *read_input();
int is_empty(char *buffer);
char **split_input(char *line);

/*print utility functions */
int print(char *str);
int print_err(char *err_reason, char *str);

/*enviroment utility functions */
char *_which(char *file);

#endif /* SHELL_H */
