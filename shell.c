#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>


/**
 * main - main entry point of the program
 * @ac: count of command line arguments
 * @av: vector of command line arguments
 *
 * Description: first version (version 0.1) of the simple shell
 * program (ALX SE project)
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	char *command = NULL;
	size_t n = 0;
	ssize_t num_chars;
	pid_t child_id;
	char *args[10];

	if (ac > 1)
		return (1);
	while (1)
	{
		printf("#cisfun$ ");
		num_chars = getline(&command, &n, stdin);
		if (num_chars == -1)
		{
			free(command);
			exit(2);
		}
		command[num_chars - 1] = '\0';
		args[0] = command;
		args[1] = NULL;
		child_id = fork();
		if (child_id == -1)
			dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
		if (child_id == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
			free(command);
			_exit(3);
		}
		if (child_id > 0)
			wait(NULL);
	}
	free(command);
	return (0);
}
