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
	char *line = NULL, **args = NULL, *string, *command, *new_str;
	size_t n = 0, size = 1;
	ssize_t num_char;
	pid_t child_id;

	num_char = getline(&line, &n, stdin);
	if (num_char == -1)
	{
		free(line);
		exit(2);
	}
	args = malloc(sizeof(char *) * size);
	if (args == NULL)
	{
		free(line);
		exit(1);
	}
	line[num_char - 1] = '\0';
	string = strtok(line, "/");
	while (string != NULL)
	{
		args[size] = strdup(string);
		string = strtok(NULL, " ");
	}
	command = get_command(args[1]);
	args[size] = NULL;

	child_id = fork();
	if (child_id == -1)
		dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
	if (child_id == 0)
	{
		  new_str = _strcat(args[0], command);
		  if (execve(new_str, av, NULL) == -1)
			dprintf(STDERR_FILENO, "%s: %s\n", av[0], strerror(errno));
	}
	if (child_id > 0)
	{
		wait(NULL);
		new_str = NULL;
	}
	printf("successful");
	(void) env;
}

char *_strcat(char const *str1, char const *str2)
{
	unsigned int len1 = 0, len2 = 0, newlen, i, j;
	char *newstr;

	if (str1 == NULL)
		len1 = 0;
	else
	{
		while (str1[len1])
			len1++;
	}

	if (str2 == NULL)
		len2 = 0;
	else
	{
		while (str2[len2])
			len2++;
	}

	newlen = len1 + len2 + 2;
	newstr = malloc(sizeof(char *) * newlen);

	if (newstr == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		newstr[i] =str1[i];
	newstr[i++] = '/';
	for (j = 0; j < len2; j++)
		newstr[i + 1 + j] = str2[j];
	newstr[i + 1 + j] = '\0';

	return (newstr);
}
