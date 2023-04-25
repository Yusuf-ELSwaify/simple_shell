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
#define ERR_MALLOC "Error: unable to allocate space\n"
/*string utility functions */
char **split_input(char *line);

/*read utility functions */
char *read_input();

#endif /* SHELL_H */
