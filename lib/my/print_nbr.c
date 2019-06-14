/*
** EPITECH PROJECT, 2018
** My Printf
** File description:
** print nums
*/

#include <stdarg.h>
#include "include/my.h"

int print_unbr(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    my_put_unbr_base(nb, "0123456789");
    return unum_len_base(nb, "0123456789");
}
