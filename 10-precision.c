#include "main.h"

/**
 * include_precision - Derives the precision for printing
 * @format: Formatted string to print the arguments
 * @i: Variable values to be printed.
 * @list: list of arguments.
 * Return: precision.
 */
int include_precision(const char *format, int *i, va_list list)
{
	int j = *i + 1;
	int precision = -1;

	if (format[j] != '.')
		return (precision);

	precision = 0;

	for (j += 1; format[j] != '\0'; j++)
	{
		if (digit(format[j]))
		{
			precision *= 10;
			precision += format[j] - '0';
		}
		else if (format[j] == '*')
		{
			j++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = j - 1;

	return (precision);
}
