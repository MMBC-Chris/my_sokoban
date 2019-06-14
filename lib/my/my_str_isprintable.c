/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** str_is_alpha
*/

#include <stdlib.h>

int is_printable(char c)
{
    return c >= 32 && c <= 126;
}

int my_str_isprintable(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++)
        if (!is_printable(str[i]))
            return 0;
    return 1;
}
