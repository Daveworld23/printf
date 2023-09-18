#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024
#define UNUSED(x) (void)(x)

#define FLAG_M 1
#define FLAG_P 2
#define FLAG_Z 4
#define FLAG_H 8
#define FLAG_S 16

#define SIZE_S 1
#define SIZE_L 2

/**
 * struct fmt - struct operation
 * @fmt: the format
 * @f: associated function
 */
struct fmt
{
	char fmt;
	int (*f)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_spc - Struct for operations
 * @fmt: The format
 * @func: The associated function
 */
typedef struct fmt fmt_spc;

int _printf(const char *format, ...);
int print_all(const char *fmt, int *n, va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_char(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_string(va_list list, char buffer[], int flags,
	       int width, int precision, int size);
int print_percent(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_int(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_binary(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_unsigned(va_list list, char buffer[], int flag,
		int width, int precision, int size);
int print_octal(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_hexa_a(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int print_hexa_A(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_hexa(va_list list, char m[], char buffer[], int flags,
		char flag_char, int width, int precision, int size);
int print_pointer(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_non_printable(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int i);
int print_reverse(va_list list, char buffer[], int flags,
		int width, int precision, int size);
int print_rot13string(va_list list, char buffer[],
		int flags, int width, int precision, int size);
int write_chars(char c, char buffer[], int flags, int width,
		int precision, int size);
int write_number(int pos, int ind, char buffer[], int flags,
		int width, int precision, int size);
int write_nums(int ind, char buff[], int flags,
		int width, int precision, int len, char padd, char c);
int write_pointer(char buffer[], int ind, int len, int flags,
		int width, char padd, char c, int padd_s);
int write_unsigned_num(int neg, int ind, char buffer[],
		int flags, int width, int precision, int size);
int printable(char);
int digit(char);
int append_hexa(char, char[], int);
long int convert_unsigned_size(unsigned long int n, int size);
long int convert_size_num(long int n, int size);

#endif
