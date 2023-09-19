#include "main.h"

/**
 * print_pointer - prints the value of a pointer
 * @list: list of arguments
 * @buffer: Buffer to handle print
 * @flags: check for flags
 * @width: define width
 * @precision: specify precision
 * @size: gets size
 * Return: Value of pointer
 */
int print_pointer(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	char c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, len = 2, padd_s = 1;
	unsigned long n_address;
	char m[] = "0123456789abcdef";
	void *address = va_arg(list, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	n_address = (unsigned long)address;
	while (n_address > 0)
	{
		buffer[ind--] = m[n_address % 16];
		n_address /= 16;
		len++;
	}
	if ((flags & FLAG_Z) && !(flags & FLAG_M))
		padd = '0';
	if (flags & FLAG_P)
		c = '+', len++;
	else if (flags & FLAG_S)
		c = ' ', len++;
	ind++;
	return (write_pointer(buffer, ind, len, width, flags, padd, c, padd_s));
}
