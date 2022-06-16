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

/*Global Environment Variable*/
extern char **environ;

/* helper functions*/
void free_args(char **args);
char *get_command(char *str);
ssize_t my_getline(char **line, size_t *len, int fd);

/* Function pointer generator*/s 
void (*get_func(char *s))(char **, char **);

/* Shell Operations */
void _list(char **av, char **env);
void my_exit(char **av, char **env);
void print_env(char **av, char **env);

/* String functions */
size_t _strlen(const char *str);
char *_strcat(char *str1, const char *str2);
char *_strdup(const char *str);
size_t _strcmp(char *str1, const char *str2);
size_t _atoi(const char *str);
size_t _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, const char *src);
ssize_t _puts(const char *str);

/* memory functions */
void *_realloc(void *old_alloc, size_t old_size, size_t new_size);

#endif /* MAIN_H_ */
