/*
** EPITECH PROJECT, 2018
** lib
** File description:
** int to char array
*/

#include <stdlib.h>
#include "my.h"

char *my_itoa(int nb)
{
    int size = num_len(nb);
    char *res = my_calloc(sizeof(char), size + 1);
    int i = size;
    int off = 1;

    if (nb < 0) {
        res[0] = '-';
        off = 0;
        nb = -nb;
    }
    while (i > 0) {
        res[i - off] = '0' + (nb % 10);
        i--;
        nb /= 10;
    }
    return res;
}
