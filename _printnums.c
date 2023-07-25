#include <unistd.h>
#include <stdlib.h>

/**
 * _printint - Helper function to print an integer directly to stdout.
 * @num: The integer to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printint(int num)
{
	char buffer[20]; /*Assume that 20 charaters are enough for an int*/
	int count = 0;
	int i = sizeof(buffer) - 1;

	if (num == 0)/*Handle Zero */
	{
		buffer[0] = 48;
		buffer[1] = 0;
		count++;
		write(1, buffer, 1);
		return (count);
	}
	if (num < 0)/*Handle Negative numbers */
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	buffer[i--] = 0;/*Converts the integer to a string(reversed)*/
	do {
		buffer[i--] = 48 + (num % 10);
		num /= 10;
		count++;
	} while (num > 0);
	write(1, buffer + i + 1, count);/*Write the string to the stdout */
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
