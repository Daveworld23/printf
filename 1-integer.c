#include "main.h"

/**
 * print_int - Function that prints integers
 * @list: list of arguments
 * @buffer: An array buffer to handle print
 * @flags: check flags
 * @width: get width
 * @precision: specify precision
 * @size: specify size
 * Return: Intergers printed
 */
int print_int(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int neg = 0;
	long int t = va_arg(list, long int);
	unsigned long int n;

	t = convert_size_num(t, size);
	if (t == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)t;
	if (t < 0)
	{
		n = (unsigned long int)((-1) * t);
		neg = 1;
	}
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_number(neg, i, buffer, flags, width, precision, size));
}
