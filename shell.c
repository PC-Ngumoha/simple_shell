#include "main.h"

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
	char *word, **args = NULL, *line = NULL;
	size_t size = 1, n = 0;
	ssize_t num_chars;
	pid_t child_id;

	if (ac != 1)
		return (1);
	while (1)
	{
		printf("#cisfun$ ");
		num_chars = getline(&line, &n, stdin);
		if (num_chars == -1)
		{
			free_args(args, size);
			free(line);
			exit(2);
		}
		args = (char **) malloc(sizeof(char *) * size);
		if (args == NULL)
		{
			free(line);
			exit(1);
		}
		line[num_chars - 1] = '\0';
		word = strtok(line, " ");
		while (word != NULL)
		{
			args[size - 1] = strdup(word);
			size++;
			args = (char **)realloc(args, sizeof(char *) * size);
			word = strtok(NULL, " ");
		}
		args[size - 1] = NULL;
		child_id = fork();
		if (child_id == -1)
			dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
		if (child_id == 0)
		{
			if (execve(*args, args, NULL) == -1)
			{
				dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
				free_args(args, size);
			}
			free(line);
			_exit(3);
		}
		if (child_id > 0)
		{
			wait(NULL);
			free_args(args, size);
			size = 1;
			args = NULL;
		}
	}
	free(line);
	free_args(args, size);
	return (0);
}
