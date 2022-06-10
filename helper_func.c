#include "main.h"

/**
 * _strlen - function to return length of string
 * @s: array pointer
 *
 * Return: length of string
 */

int _strlen(const char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _strdup - function to return duplicates of string
 * @str: array pointer
 *
 * Return: duplicate of string
 */
char *_strdup(const char *str)
{
	char *string;
	int length, i = 0;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	string = malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';

	return (string);
}
