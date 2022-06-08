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
 *
 * Description: first version (version 0.1) of the simple shell
 * program (ALX SE project)
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *command;
	size_t n = 32;
	ssize_t num_chars;
	pid_t child_id;
	char *args[10];

	command = malloc(sizeof(char) * (n + 1));
	if (command == NULL)
	{
		dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
		exit(1);
	}
	while (1)
	{
		printf("#cisfun$ ");
		num_chars = getline(&command, &n, stdin);
		if (num_chars == -1)
			exit(2);
		command[num_chars - 1] = '\0';
		args[0] = command;
		args[1] = NULL;
		child_id = fork();
		if (child_id == -1)
			dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
		if (child_id == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				dprintf(STDERR_FILENO, "Error: %s\n", strerror(errno));
			_exit(3);
		}
		if (child_id > 0)
			wait(NULL);
	}
	return (0);
}
