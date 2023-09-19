#include "main.h"
/**
 * print_reverse - Prints reverse string.
 * @list: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Specifies Precision
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int print_reverse(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int n, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (n = 0; str[n]; n++)
		;

	for (n = n - 1; n >= 0; n--)
	{
		char z = str[n];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
