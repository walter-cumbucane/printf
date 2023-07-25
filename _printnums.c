#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _putchar - Helper function to print a single character to stdout.
 * @c: The character to be printed.
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printint - Helper function to print an integer directly to stdout.
 * @num: The integer to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printint(int num)
{
	char buffer[20]; /* Assume that 20 characters are enough for an int */
	int count = 0;
	int i = sizeof(buffer) - 1;

	if (num == 0)/* Handle Zero */
	{
		buffer[0] = '0';
		buffer[1] = '\0';
		count++;
		_putchar('0');
		return (count);
	}
	if (num < 0)/* Handle Negative numbers */
	{
		_putchar('-');
		count++;
		num = -num;
	}
	buffer[i--] = '\0';/* Converts the integer to a string (reversed) */
	do {
		buffer[i--] = '0' + (num % 10);
		num /= 10;
		count++;
	} while (num > 0);
	_putchar(buffer[i + 1]);/* Write the string to the stdout */
	return (count);
}

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += write(1, va_arg(args, char *), count);
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += _printint(va_arg(args, int));
					break;
				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * _printbin - Helper function to print a binary directly to stdout.
 * @num: The integer to be printed in binary
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printbin(int num)
{
	int num_bits = sizeof(num) * 8;
	char *binary;
	int i;
	int count = 0;

	if (num < 0)/*Handle negative numbers */
		return (0);
	if (num == 0)/* Handle zero */
	{
		write(1, "0", 1);
		return (1);
	}
	binary = malloc((num_bits + 1) * sizeof(char));
	for (i = num_bits - 1; i >= 0; i--)/*loop through each bit of num*/
	{
		if (num & (1 << i))/*Determines whether the bit "i" is 1 or 0*/
			*(binary + num_bits - i - 1) = '1';
		else
			*(binary + num_bits - i - 1) = '0';
	}
	*(binary + num_bits) = '\0';
	i = 0;
	while (*(binary + i) != 0)
	{
		while (*(binary + i) != '1')
		{
			i++;
			continue;
		}
		break;
	}
	while (*(binary + i) != 0)
	{
		write(1, binary + i, 1);
		count++;
		i++;
	}
	free(binary);
	return (count);
}
