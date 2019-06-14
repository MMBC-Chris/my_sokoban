/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strupcase
*/

#include <stdlib.h>

char *my_strupcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return NULL;
    for (; str[i]; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';
    return str;
}
