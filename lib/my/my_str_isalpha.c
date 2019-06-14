/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** str_is_alpha
*/

#include <stdlib.h>

int is_alpha(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i]; i++)
        if (!is_alpha(str[i]))
            return 0;
    return 1;
}
