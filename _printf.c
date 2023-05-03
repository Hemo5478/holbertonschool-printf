#include "main.h"

int _printf(const char *format, ...)
{
	char c;
	int hemo;

	va_list args;
	va_start(args, format);

	hemo = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				putchar(c);
				hemo++;
			}
			else if (*format == 's')
			{
				const char *str = va_arg(args, const char *);
				_print_str(str);
				hemo += _strlen(str);
			}
			else if (*format == '%')
			{
				putchar('%');
				hemo++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				hemo += hemo + 2;
			}
		}
		else
		{
			putchar(*format);
			hemo++;
		}
		format++;
	}

	va_end(args);

	return (hemo);
}
