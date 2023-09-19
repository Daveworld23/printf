#include "main.h"

/**
 * include_size -Calculates size
 * @format: Formatted string to print the arguments
 * @i:values to be printed.
 * Return: Size.
 */
int include_size(const char *format, int *i)
{
	int j = *i + 1;
	int size = 0;

	if (format[j] == 'l')
		size = SIZE_L;
	else if (format[j] == 'h')
		size = SIZE_S;

	if (size == 0)
		*i = j - 1;
	else
		*i = j;

	return (size);
}
