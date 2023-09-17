#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
int print_all(const char *fmt, int *i, va_list list, char buffer[], int flags, int width, int precision, int size);

#endif
