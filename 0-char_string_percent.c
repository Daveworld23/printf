#include "main.h"
/*****PRINT CHAR TO STDOUT******/
/**
 * print_char - function that prints a char
 * @list: the list of argument
 * @buffer: An array buffer that handles print
 * @flags: checks for flags
 * @width: checks for width
 * @precision: specification for precision
 * @size: size
 * Return: Number of chars printed
 */
int print_char(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = va_arg(list, int);

	return (write_chars(c, buffer, flags, width, precision, size));
}
/***PRINT A STRING TO STDOUT***/
/**
 * print_string - function that prints a string
 * @list: list of arguments
 * @buffer: Array of buffer to handle print
 * @flags: checks for flags
 * @width: checks for width
 * @precision: specification of precision
 * @size: size
 * Return: String printed
 */
int print_string(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "     ";
	}
	while (str[len] != '\0')
		len++;
	if (precision >= 0 && precision < len)
		len = precision;
	if (width > len)
	{
		if (flags & FLAG_M)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/*******PRINT PERCENT SIGN******/
/**
 * print_percent - function that prints the percent size
 * @list: list of arguments
 * @buffer: Buffer array to handle print
 * @flags: checks for flags
 * @width: checks for width
 * @precision: specification of precision
 * @size: size
 * Return: number of chars printed
 */
int print_percent(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
