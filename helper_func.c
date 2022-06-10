#include "main.h"


/**
 * free_args - frees up the memory allocated to an array of strings
 * @args: dynamically allocated array of strings
 * @size: size of the dynamically allocated array
 *
 * Return: void
 */
void free_args(char **args, size_t size)
{
	size_t i;

	if (args == NULL)
		return;
	for (i = 0; i < size; i++)
		free(args[i]);
	free(args);
}
