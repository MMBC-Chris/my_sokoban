/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** put nbr base
*/

#include "include/my.h"

void pnbr_base(long nb, char const *base)
{
    int base_len = my_strlen(base);

    if (nb) {
        pnbr_base(nb / base_len, base);
        my_putchar(base[nb % base_len]);
    }
}

void punbr_base(unsigned long nb, char const *base)
{
    int base_len = my_strlen(base);

    if (nb) {
        punbr_base(nb / base_len, base);
        my_putchar(base[nb % base_len]);
    }
}

int my_put_nbr_base(long nb, char const *base)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb != 0)
        pnbr_base(nb, base);
    else
        my_putchar(base[nb]);
    return 0;
}

int my_put_unbr_base(unsigned long nb, char const *base)
{
    if (nb != 0)
        punbr_base(nb, base);
    else
        my_putchar(base[nb]);
    return 0;
}
