/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** str_is_alpha
*/

#include <stdlib.h>

int is_digit(char c)
{
    return c >= '0' && c <= '9';
}

int my_str_isnum(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++)
        if (!is_digit(str[i]))
            return 0;
    return 1;
}
