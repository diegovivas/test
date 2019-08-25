#include "head.h"
#include <stdarg.h>
#include <stdint.h>

int _withformat(char c, int count, va_list valist)
{
	int j, i;
	char *s;
	char si[6] = "(null)";
	
	switch (c)
	{
	case 's':
		s = va_arg(valist, char *);
		if (!s)
		{
			for (i = 0; si[i]; i++, count++)
				_putchar(si[i]);
		}
		else
			count += _printstring(s);
		break;
	case 'd':
		j = va_arg(valist, int);
		
		if (!j)
		{
			count++;
			_putchar('0');
		} else
			count += print_number(j);
		break;
        default:
                count += 2;
                _putchar('%');
                _putchar(c);
	}
	return (count);
}

/**
 * _printf - Fuction that prints to the std output
 * @format: list of parameters passed
 * Return: @count the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	va_list valist;

	va_start(valist, format);

	if (!format)
		return (-1);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			count++;
			_putchar(format[i]);
		}
		else if (format[i + 1])
		{
			i++;
			count = _withformat(format[i], count, valist);
		}
		else
			return (-1);
	}
	va_end(valist);
	return (count);
}
