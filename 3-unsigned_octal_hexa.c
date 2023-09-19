#include "main.h"
/***** PRINT UNSINGNED NUMBER *******/
/**
 * print_unsigned - prints an unsigned number
 * @list: list of arguments
 * @buffer: buffer array to store print
 * @flags: checks available flags
 * @width: gets widtg
 * @precision: specify precision
 * @size: specify size
 * Return: the unsigned number
 */
int print_unsigned(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(list, unsigned long int);

	n = convert_unsigned_size(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_unsigned_num(0, i, buffer, flags, width, precision, size));
}
/***** PRINT OCTAL *****/
/**
 * print_octal - prints in octal notation
 * @list: list of arguments
 * @buffer: buffer array that handles print
 * @flags: calculates fkags
 * @width: gets width
 * @precision: soecifies precision
 * @size: define size
 * Return: The octal notation
 */
int print_octal(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(list, unsigned long int);
	unsigned long int num = n;

	UNUSED(width);
	n = convert_unsigned_size(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (flags & FLAG_H && num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsigned_num(0, i, buffer, flags, width, precision, size));
}
/***** PRINT LOWER HEXADECIMAL *****/
/**
 * print_hexa_a - prints in hexadecimal notation
 * @list: list of arguments
 * @buffer: buffer array to help print
 * @flags: calculate flags
 * @width: defines width
 * @precision: soecifies precision
 * @size: gets size
 * Return: The hexadecimal notation
 */
int print_hexa_a(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(list, "0123456789abcdef", buffer, flags,
				'x', width, precision, size));
}
/**** PRINT UPPER HEXADECIMAL ***/
/**
 * print_hexa_A - prints upper hexadecimal numbers
 * @list: list of arguments
 * @buffer: buffer to store numbers
 * @flags: get active flags
 * @width: checks for width
 * @precision: sspecificatiom of precision
 * @size: define size
 * Return: The upper hecadecimal notatiion
 */
int print_hexa_A(va_list list, char buffer[], int flags,
		int width, int precision, int size)
{
	return (print_hexa(list, "0123446789ABCDEF", buffer, flags,
				'X', width, precision, size));
}
/**** PRINT HEXADECIMAL IN UPPER OR LOWER ***/
/**
 * print_hexa - prints upper or lowee hexadecimals
 * @list: list of arguments
 * @m: An array of numbers to allow mapping
 * @buffer: buffer array to handle print
 * @flags: calculate available flags
 * @flag_char: checks for flags
 * @width: gets width
 * @precision: Specifies precision
 * @size: specifies size
 * Return: the hexadecimal notation
 */
int print_hexa(va_list list, char m[], char buffer[], int flags,
		char flag_char, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(list, unsigned long int);
	unsigned long int num = n;

	UNUSED(width);

	n = convert_unsigned_size(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = m[n % 16];
		n /= 16;
	}
	if (flags & FLAG_H && num != 0)
	{
		buffer[i--] = flag_char;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsigned_num(0, i, buffer, flags, width, precision, size));
}
