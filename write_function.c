#include "main.h"
/**** WRITE CHAR ****/
/**
 * write_chars - prints a string
 * @c: character type
 * @buffer: Buffer to handle print
 * @flags: calculates flags
 * @width: checks for width
 * @precision: specify precision
 * @size: define size
 * Return: Chars printed
 */
int write_chars(char c, char buffer[], int flags, int width,
		int precision, int size)
{
	int i = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & FLAG_Z)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';
	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = padd;
		if (flags & FLAG_M)
			return (write(1, &buffer[0], 1) + write(1,
						&buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}
	return (write(1, &buffer[0], 1));
}
/**** WRITE NUMBER ***/
/**
 * write_number - prints a string
 * @neg: a list of argument
 * @ind: the character type
 * @buffer: buffer that handles print
 * @flags: define flags
 * @width: check for width
 * @precision: specify precision
 * @size: check size
 * Return: chars printed
 */
int write_number(int neg, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1;
	char padd = ' ', c = 0;

	UNUSED(size);
	if ((flags & FLAG_Z) && !(flags & FLAG_M))
		padd = '0';
	if (neg)
		c = '-';
	else if (flags & FLAG_P)
		c = '+';
	else if (flags & FLAG_S)
		c = ' ';
	return (write_nums(ind, buffer, flags, width, precision,
				len, padd, c));
}
/**** WRITE NUM ***/
/**
 * write_nums - write a number to be printed
 * @ind: index of the number
 * @buffer: buffer that handle printing
 * @flags: calculates flags
 * @width: checks for width
 * @prcs: specifies precision
 * @len: lenth of number
 * @padd: pades char
 * @c: the extra char
 * Return: Number of chars printed
 */
int write_nums(int ind, char buffer[], int flags, int width,
		int prcs, int len, char padd, char c)
{
	int i, padd_s = 1;

	if (prcs == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prcs == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';
	if (prcs > 0 && prcs < len)
		padd = ' ';
	while (prcs > len)
		buffer[--ind] = '0', len++;
	if (c != 0)
		len++;
	if (width > len)
	{
		for (i = 1; i < width - len + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FLAG_M && padd == ' ')
		{
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[ind], len) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & FLAG_M) && padd == ' ')
		{
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], len));
		}
		else if (!(flags & FLAG_M) && padd == '0')
		{
			if (c)
				buffer[--padd_s] = c;
			return (write(1, &buffer[padd_s], i - padd_s) +
					write(1, &buffer[ind], len - (1 - padd_s)));
		}
	}
	if (c)
		buffer[--ind] = c;
	return (write(1, &buffer[ind], len));
}
/**** WRITE UNSIGNED NUMBER ***/
/**
 * write_unsigned_num - writes an unsigned number
 * @neg: indicator for negative number
 * @ind: index of number
 * @buffer: an array of chars
 * @flags: get flags
 * @width: checks available width
 * @precision: specifies precision
 * @size: defines size
 * Return: number of chars
 */
int write_unsigned_num(int neg, int ind, char buffer[],
		int flags, int width, int precision, int size)
{
	int len = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(neg);
	UNUSED(size);
	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);
	if (precision > 0 && precision < len)
		padd = ' ';
	while (precision > len)
	{
		buffer[--ind] = '0';
		len++;
	}
	if ((flags & FLAG_Z) && !(flags & FLAG_M))
		padd = '0';
	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = padd;
		buffer[i] =  '\0';
		if (flags & FLAG_M)
		{
			return (write(1, &buffer[ind], len) + write(
						1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1,
						&buffer[ind], len));
		}
	}
	return (write(1, &buffer[ind], len));
}
/*** WRITE POINTERS ****/
/**
 * write_pointer - writes memory address
 * @buffer: array buffer of char
 * @ind: index of number
 * @len: length of number
 * @flags: gets flags
 * @width: gets width
 * @padd: pads char
 * @c: extra character
 * @padd_s: index for padding
 * Return: number of char written
 */
int write_pointer(char buffer[], int ind, int len, int flags, int width,
		char padd, char c, int padd_s)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = padd;
		buffer[i] = '\0';
		if (flags & FLAG_M && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[ind], len) + write(1,
						&buffer[3], i - 3));
		}
		else if (!(flags & FLAG_M) && padd == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (c)
				buffer[--ind] = c;
			return (write(1, &buffer[3], i - 3) + write(1,
						&buffer[ind], len));
		}
		else if (!(flags & FLAG_M) && padd == '0')
		{
			if (c)
				buffer[--padd_s] = c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_s], i - padd_s)
					+ write(1, &buffer[ind], len - (1 - padd_s) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (c)
		buffer[--ind] = c;
	return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
