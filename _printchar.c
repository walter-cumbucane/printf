#include <unistd.h>
#include "main.h"

/**
 * _printchar - Helper function to print a char directly to stdout.
 * @c: The char to be printed.
 *
 * Return: The number of characters printed.
 */

int _printchar(int c)
{
	int count;

	count = write(1, &c, 1);
	return (count);
}


/**
 * _printstr - Helper function to print an integer directly to stdout.
 * @s: The string to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printstr(char *s)
{
	int count;

	count = write(1, s, _strlen(s));
	return (count);
}
