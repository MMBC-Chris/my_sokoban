/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** str_is_alpha
*/

#include <stdlib.h>

int is_lower(char c)
{
    return c >= 'a' && c <= 'z';
}

int my_str_islower(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++)
        if (!is_lower(str[i]))
            return 0;
    return 1;
}
