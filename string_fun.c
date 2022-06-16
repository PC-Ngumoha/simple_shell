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
		str1[i] = str2[j];
		j++;
		i++;
	}

	return (str1);
}

/**
 * _strcmp - function to compare strings
 * @str1: first string
 * @str2: second string
 *
 * Return: difference between both string
 */
size_t _strcmp(char *str1, char *str2)
{
	size_t i = 0;

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] -str2[i]);
		}
		i++;
	}

	return (0);
}


