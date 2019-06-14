/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** str_is_alpha
*/

#include <stdlib.h>

int is_upper(char c)
{
    return c >= 'A' && c <= 'Z';
}

int my_str_isupper(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++)
        if (!is_upper(str[i]))
            return 0;
    return 1;
}
