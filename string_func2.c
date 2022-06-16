#include "main.c"

/**
 * _strdup - duplicates a string in memory
 * @str: string to duplicate
 *
 * Return: pointer to duplicate of the string
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t i, length;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}
