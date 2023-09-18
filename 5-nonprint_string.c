#include "main.h"
/**
 * print_non_printable - Prints strings in hexa using ascii codes
 * @list: list of arguments
 * @buffer: buffer storage
 * @flags: calculate flags
 * @width: gets width
 * @precision: specifies precision
 * @size: gets size
 * Return: Printed string
 */
int print_non_printable(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = 0, var = 0;
	char *str = va_arg(list, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (printable(str[i]))
			buffer[i + var] = str[i];
		else
			var += append_hexa(str[i], buffer, i + var);
		i++;
	}
	buffer[i + var] = '\0';
	return (write(1, buffer, i + var));
}
