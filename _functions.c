#include "main.h"

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
