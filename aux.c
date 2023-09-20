#include "main.h"

/**
 * printable - Checks if a char is printable
 * @c: Char to be evaluated.
 *
 * Return: 1 if printable, 0 otherwise
 */
int printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa - Append ascci in hexadecimal code
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 *
 * Return: Always 3
 */
int append_hexa(char ascii_code, char buffer[], int i)
{
	char m[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = m[ascii_code / 16];
	buffer[i] = m[ascii_code % 16];

	return (3);
}

/**
 * digit - checks if a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_num - Converts a number to a specified size
 * @n: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Value of n
 */
long int convert_size_num(long int n, int size)
{
	if (size == SIZE_L)
		return (n);
	else if (size == SIZE_S)
		return ((short)n);

	return ((int)n);
}

/**
 * convert_unsigned_size - Assigns a number to a specified size
 * @n: Number to be assigned
 * @size: Size of assigned number
 *
 * Return: Casted value of n
 */
long int convert_unsigned_size(unsigned long int n, int size)
{
	if (size == SIZE_L)
		return (n);
	else if (size == SIZE_S)
		return ((unsigned short)n);

	return ((unsigned int)n);
}
