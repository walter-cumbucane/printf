#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - a printf like function.
 * @format: The string containing the info to be printed to stdout.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int i = 0;
	int count = 0;

	va_start(ptr, format);
	if ((format == NULL) || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (*(format + i) != 0)
	{
		if (*(format + i) == '%')
		{
			i++;
			if (*(format + i) == 'c')
				count += _printchar(va_arg(ptr, int));
			else if (*(format + i) == 's')
				count += _printstr(va_arg(ptr, char *));
			else if (*(format + i) == 'd' || *(format + i) == 'i')
				count += _printint(va_arg(ptr, int));
			else if (*(format + i) == 'u')
				count += _printint(va_arg(ptr, int));
			else if (*(format + i) == 'b')
				count += _printbin(va_arg(ptr, int));
			else if (*(format + i) == '%')
				count += _printpercent(37);
			else
				count += write(1, (format + i - 1), 2);
			i++;
		}
		else
		{
			write(1, (format + i), 1);
			count++;
			i++;
		}
	}
	va_end(ptr);
	return (count);
}
