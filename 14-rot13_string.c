#include "main.h"

/**
 * print_rot13string - Print a string in rot13.
 * @list: List of arguments
 * @buffer: Buffer to handle print
 * @flags:  Calculates available flags
 * @width: get width
 * @precision: Specify Precision
 * @size: Derive Size
 * Return: Numbers of chars printed
 */

int print_rot13string(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char c;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				c = out[j];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			c = str[i];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
