/*
** EPITECH PROJECT, 2018
** My printf
** File description:
** format print
*/

#include <stdarg.h>
#include "include/my.h"

int num_len(long nb)
{
    int size = 0;

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb = -nb;
        size++;
    }
    while (nb) {
        size++;
        nb /= 10;
    }
    return size;
}

int num_len_base(long nb, char const *base)
{
    int size = 0;
    int base_len = my_strlen(base);

    if (nb == 0)
        return 1;
    if (nb < 0) {
        nb = -nb;
        size++;
    }
    while (nb) {
        size++;
        nb /= base_len;
    }
    return size;
}

int unum_len_base(unsigned long nb, char const *base)
{
    int size = 0;
    int base_len = my_strlen(base);

    if (nb == 0)
        return 1;
    while (nb) {
        size++;
        nb /= base_len;
    }
    return size;
}

int print_int(va_list ap)
{
    int nb = va_arg(ap, int);

    my_put_nbr(nb);
    return num_len(nb);
}

int print_uint(va_list ap)
{
    unsigned int nb = va_arg(ap, unsigned int);

    my_put_unbr_base(nb, "0123456789");
    return unum_len_base(nb, "0123456789");
}
