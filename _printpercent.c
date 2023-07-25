#include <unistd.h>
#include "main.h"

/**
 * _printpercent - Helper function to print a char directly to stdout.
 * @num: The char to be printed.
 *
 * Return: The number of characters printed.
 */

int _printpercent(int num)
{
	int count;

	count = write(1, &num, 1);
	return (count);
}
