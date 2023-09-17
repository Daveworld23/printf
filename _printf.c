#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - A printf function
 * @format: print format
 * Return: chars printed
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, chars_printed = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = include_flags(format, &i);
			width = include_width(format, &i, list);
			precision = include_precision(format, &i, list);
			size = include_size(format, &i);
			++i;
			printed = print_all(format, &i, buffer, list, flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars_printed += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (chars_printed);
}
/**
 * print_buffer - prints content of buffer if available
 * @buffer: Array of chars
 * @buff_ind: the length index to which next char is added
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
