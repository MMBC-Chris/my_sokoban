/*
** EPITECH PROJECT, 2018
** My Printf
** File description:
** short file description
*/

#include <stdarg.h>
#include "include/my.h"

int print_ubin(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    my_put_unbr_base(nb, "01");
    return unum_len_base(nb, "01");
}
