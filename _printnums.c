#include <unistd.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printint - Helper function to print an integer directly to stdout.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printint(int n)
{
	int num, last = n % 10, digit, exp = 1;
	int  i = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
}

/**
 * _printdec - Helper function to print a decimal value directly to stdout.
 * @n: The integer to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */

int _printdec(int n)
{
	int num, last = n % 10, digit;
	int  i = 1;
	int exp = 1;

	n = n / 10;
	num = n;

	if (last < 0)
	{
		_putchar('-');
		num = -num;
		n = -n;
		last = -last;
		i++;
	}
	if (num > 0)
	{
		while (num / 10 != 0)
		{
			exp = exp * 10;
			num = num / 10;
		}
		num = n;
		while (exp > 0)
		{
			digit = num / exp;
			_putchar(digit + '0');
			num = num - (digit * exp);
			exp = exp / 10;
			i++;
		}
	}
	_putchar(last + '0');

	return (i);
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
