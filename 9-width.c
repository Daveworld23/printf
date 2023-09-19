#include "main.h"

/**
 * include_width - Derives the width for printing
 * @format: Formatted string to print the arguments.
 * @i: values to be printed.
 * @list: list of arguments.
 * Return: width.
 */
int include_width(const char *format, int *i, va_list list)
{
	int j;
	int width = 0;

	for (j = *i + 1; format[j] != '\0'; j++)
	{
		if (digit(format[j]))
		{
			width *= 10;
			width += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (width);
}
