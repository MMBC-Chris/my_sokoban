/*
** EPITECH PROJECT, 2018
** My printf
** File description:
** format print
*/

#include <stdarg.h>
#include "include/my.h"

int print_str(va_list ap)
{
    char *str = va_arg(ap, char *);

    my_putstr(str);
    return my_strlen(str);
}

int print_invisible_str(va_list ap)
{
    char *str = va_arg(ap, char *);
    int print_size = 0;

    while (*str) {
        if (*str >= 32 && *str <= 127)
            my_putchar(*str);
        else {
            my_putchar('\\');
            my_putchar(48 + *str / 64 % 8);
            my_putchar(48 + *str / 8 % 8);
            my_putchar(48 + *str % 8);
            print_size += 3;
        }
        print_size++;
        str++;
    }
    return print_size;
}

int print_char(va_list ap)
{
    my_putchar(va_arg(ap, int));
    return 1;
}
