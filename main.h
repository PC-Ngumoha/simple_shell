#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct option_type - represents possible commands and operations
 * @command: stores the string of the command
 * @func: pointer to the function that executes the operation
 *
 * Description: helps in analysing the input into the shell by the
 * user and determining what the appropriate operation to carry out
 * is based on the input strings.
 */
typedef struct option_type
{
	char *command;
	void (*func)(char **av, char **env);
} options;

/* helper functions */
void free_args(char **args, size_t size);

/* Function pointer generators */
void (*get_func(char *s))(char **, char **);

/* Shell Operations */
void _list(char **av, char **env);

#endif /* MAIN_H_ */
