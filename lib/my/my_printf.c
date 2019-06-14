/*
** EPITECH PROJECT, 2018
** My printf
** File description:
** my printf
*/

#include <stdarg.h>
#include "include/my.h"
#include "include/printf.h"

int print_fmt(va_list ap, char const *fmt)
{
    int i = 0;

    if (*fmt == '%') {
        my_putchar(*fmt);
        return 1;
    }
    while (i < FORMATS_NUM) {
        if (!my_strncmp(PRINTF_FORMATS[i].identifier, fmt,
                        my_strlen(PRINTF_FORMATS[i].identifier)))
            return (PRINTF_FORMATS[i].print)(ap);
        i++;
    }
    return 0;
}

int my_printf(char const *format, ...)
{
    int print_size = 0;
    int i = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i]) {
        if (format[i] == '%') {
            i++;
            print_size += print_fmt(ap, format + i);
        }
        else {
            my_putchar(format[i]);
            print_size++;
        }
        i++;
    }
    va_end(ap);
    return print_size;
}
