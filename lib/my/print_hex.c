/*
** EPITECH PROJECT, 2018
** My Printf
** File description:
** short file description
*/

#include <stdarg.h>
#include "include/my.h"

int print_hex_lwc(va_list ap)
{
    int nb = va_arg(ap, int);

    my_put_nbr_base(nb, "0123456789abcdef");
    return num_len_base(nb, "0123456789abcdef");
}

int print_hex_upc(va_list ap)
{
    int nb = va_arg(ap, int);

    my_put_nbr_base(nb, "0123456789ABCDEF");
    return num_len_base(nb, "0123456789ABCDEF");
}

int print_ptr(va_list ap)
{
    void *ptr = va_arg(ap, void *);

    my_putstr("0x");
    my_put_unbr_base((unsigned long)(ptr), "0123456789abcdef");
    return 2 + unum_len_base((unsigned long)(ptr), "0123456789abcdef");
}

int print_octal(va_list ap)
{
    int nb = va_arg(ap, int);

    my_put_nbr_base(nb, "01234567");
    return num_len_base(nb, "01234567");
}
