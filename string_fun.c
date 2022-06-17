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
char *_strcat(char *str1, const char *str2)
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
int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while ((str1[i] != '\0' && str2[i] != '\0') && (str1[i] == str2[i]))
		i++;

	if (str1[i] == str2[i])
		return (0);
	else
		return (str1[i] - str2[i]);
}

/**
 * _atoi - function to convert string to integer
 * @str: string to be converted
 *
 * Return: integer gotten
 */
size_t _atoi(const char *str)
{
	size_t num = 0, i = 0;
	int sign = 1;

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = (num * 10) + (str[i] - '0');

			if (str[i + 1] == ' ')
				break;
		}

		else if (str[i] == '-')
			sign *= -1;
		i++;
	}

	return (num * sign);
}

/**
 * _puts - function to print strings to std input
 * @str: character to print out
 *
 * Return: character printed out
 */
ssize_t _puts(const char *str)
{
	size_t len = _strlen(str);

	return (write(1, str, len));
}

/**
 * _strncat - appends a number of character of a string to another
 * @dest: destination string
 * @src: source string
 * @count: specified number
 *
 * Return: pointer to the appended string
 */
char *_strncat(char *dest, const char *src, size_t count)
{
	size_t i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (j < count && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
