#include "main.h"

/**
 * _strlen - function to return the length of string
 * @str: string passed to check length
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * _strcat - function to concatenate
 * @str1: the string to append
 * @str2: string to be joined
 * 
 * Return: the concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	size_t i = 0, j = 0;

	while (str1[i] != '\0')
		i++;

	while (str2[j] != '\0')
	{
		str1[j] = str2[i];
		j++;
		i++;
	}

	return (str1);
}
