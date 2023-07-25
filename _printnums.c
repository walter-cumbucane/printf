#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - Helper function to write a single character to stdout.
 * @c: The character to be written.
 *
 * Return: On success, returns the number of characters written.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return write(1, &c, 1);
}

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 *         On error, -1 is returned.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
			case 'c':
			{
				char ch = va_arg(args, int);
				count += _putchar(ch);
				break;
			}
			case 's':
			{
				char *str = va_arg(args, char *);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					count += _putchar(*str);
					str++;
				}
				break;
			}
			case '%':
				count += _putchar('%');
				break;
			case 'd':
			case 'i':
			{
				int num = va_arg(args, int);
				int temp = num;
				int digits = 0;

				if (num == 0)
				{
					count += _putchar('0');
					break;
				}

				if (num < 0)
				{
					count += _putchar('-');
					num = -num;
				}

				while (temp != 0)
				{
					digits++;
					temp /= 10;
				}

				while (digits--)
				{
					int digit = num / pow(10, digits);
					count += _putchar(digit + '0');
					num %= (int)pow(10, digits);
				}

				break;
			}
			default:
				count += _putchar('%');
				count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);

	return count;
}
