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
	char *word, *command, *token, *line = NULL, **args = NULL;
	size_t size = 1, n = 0;
	ssize_t num_char;
	void (*func)(char **, char **);

	if (ac != 1)
		return (1);
	while (1)
	{
		printf("#cisfun$ ");
		num_char = getline(&line, &n, stdin);
		if (num_char == -1)
		{
			free(line);
			exit(1);
		} line[num_char - 1] = '\0';
		args = malloc(sizeof(char *) * size);
		if (args == NULL)
		{
			dprintf(STDERR_FILENO, "Not enough memory\n");
			free(line);
			exit(1);
		}
		while (word != NULL)
		{
			args[size - 1] = strdup(word);
			args = realloc(args, sizeof(char *) * (++size));
			word = strtok(NULL, " ");
		} args[size - 1] = NULL, command = strdup(args[0]);
		token = strtok(command, "/");
		while (token != NULL)
		{
			command = strdup(token);
			token = strtok(NULL, "/");
		} args[0] = strdup(command), func = get_func(args[0]);
		if (!func)
			dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
		else
			func(args, NULL);
		free_args(args, size), size = 1, args = NULL;

	} free(line);
	return (0);
}
