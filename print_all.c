#include "main.h"
/**
 * print_all - prints arguments based on input type
 * @fmt: formatted string
 * @n: the array index
 * @list: list of arguments
 * @buffer: Buffer to handle print
 * @flags: calculate flags
 * @width: gets width
 * @precision: specify precision
 * @size: specify size
 * Return: 1 or 2;
 */
int print_all(const char *fmt, int *n, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, chars_printed = -1;
	fmt_spc fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'d', print_int}, {'i', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexa_a},
		{'X', print_hexa_A}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*n] == fmt_types[i].fmt)
			return (fmt_types[i].f(list, buffer, flags, width, precision, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*n] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (fmt[*n - 1] == ' ')
			unknown_len += write(1, " ", 1);
		else if (width)
		{
			--(*n);
			while (fmt[*n] != ' ' && fmt[*n] != '%')
				--(*n);
			if (fmt[*n] == ' ')
				--(*n);
			return (1);
		}
		unknown_len += write(1, &fmt[*n], 1);
		return (unknown_len);
	}
	return (chars_printed);
}
