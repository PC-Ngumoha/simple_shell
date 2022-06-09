#include "main.h"

/**
 * _strlen - function to return length of string
 * @s: array pointer
 *
 * Return: length of string
 */

int _strlen(char *s)
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

char *_strdup(char *str)
{
	char *string;

	string = malloc(_strlen(str) * sizeof(char *));

	if (string == NULL)
		return (NULL);

	if (string != NULL)
	{
		strcpy(string, str);
	}

	return (string);
}
