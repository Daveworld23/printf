#include "main.h"

/**
 * print_binary - An unsigned int converted to binary
 * @list: list of arguments
 * @buffer: Buffer array to store print
 * @flags: checks available flags
 * @width: checks available width
 * @precision: specifies precision
 * @size: specifies size
 * Return: Binary count
 */
int print_binary(va_list list,  char buffer[], int flags,
		int width, int precision, int size)
{
	unsigned int i, j, k, sum;
	unsigned int n[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	i = va_arg(list, unsigned int);
	j = 2147483648;
	n[0] = i / j;
	for (k = 1; k < 32; k++)
	{
		j /= 2;
		n[k] = (i / j) % 2;
	}
	for (k = 0, sum = 0, count = 0; k < 32; k++)
	{
		sum += n[k];
		if (sum || k == 31)
		{
		char b = '0' + n[k];

		write(1, &b, 1);
		count++;
		}
	}
	return (count);
}
