#include "main.h"
#include <unistd.h>

/**
 * _strlen - Returns the length of a string.
 * @s: The string to be tested.
 *
 * Return: The number of characters of the given string.
 */

int _strlen(char *s)
{
	int len = 0;
	int i = 0;

	while (*(s + i) != 0)
	{
		len++;
		i++;
	}
	return (len);
}

/**
 * _putchar - Helper function to print a single character to stdout.
 * @c: The character to be printed.
 *
 * Return: 1 on success, -1 on error.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
