#include "main.h"

/**
 * _strlen - function to return the length of string
 * @str: string passed to check length
 *
 * Return: length of string
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}
