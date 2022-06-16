#include "main.h"

/**
 * _strlen - function to return the length of string
 * @str: string passed to check length
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	unsigned int len;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

char *_strcat(char *str)
{
