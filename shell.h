#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define PROMPT "$ "
#define MAX_TOKENS 64
#define SPACES " \n\t\r\f\v"

#define ERR_MALLOC "Error: unable to allocate space\n"
/*string utility functions */
char **split_input(char *line);
char *_strchr(char *s, char c);
int _strlen(char *str);


/*read utility functions */
char *read_input();
int is_empty(char *buffer);

/*print utility functions */
int print(char *str);
int print_err(char *str);

#endif /* SHELL_H */
