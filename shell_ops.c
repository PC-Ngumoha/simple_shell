#include "main.h"

/**
 * _list - lists out the content of the current directory
 * @av: vector of arguments for the operation/command
 * @env: environment variables to work with
 *
 * Return: void
 */
void _list(char **av, char **env)
{
	char *word, *command, *string;

	size_t length1, length2, total_length;
	pid_t child_id;

	command = strdup(av[0]);
	length1 = strlen("/bin/");
	length2 = strlen(command);
	total_length = length1 + length2 + 1;
	string = malloc(sizeof(char) * total_length);
	strcpy(string, "/bin/");
	strcat(string, command);
	word = av[0];
	av[0] = strdup(string);
	free(word);
	free(string);
	free(command);

	child_id = fork();
	if (child_id == -1)
		dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
	if (child_id == 0)
		{
			if (execve(av[0], av, NULL) == -1)
				dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
			free_args(av);
			_exit(1);
		}
	if (child_id > 0)
		wait(NULL);

	(void) env;
}
