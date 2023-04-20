#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - prints a variable number of arguments
 *
 * @format: the format string containing the types of arguments
 * @...: the arguments to print
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *str, *sep = "";
	unsigned int i = 0;
	char c;

	va_start(args, format);

	while (format && format[i])
	{
		c = format[i];

		switch (c)
		{
			case 'c':
				printf("%s%c", sep, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", sep, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", sep, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", sep, str);
				break;
			default:
				i++;
				continue;
		}

		sep = ", ";
		i++;
	}

	printf("\n");

	va_end(args);
}

