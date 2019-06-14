/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strcapitalize
*/

#include <stdlib.h>

int is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_eow(char c)
{
    int cond1 = 0;
    int cond2 = 0;
    int cond3 = 0;

    cond1 = is_lowercase(c);
    cond2 = c >= 'A' && c <= 'Z';
    cond3 = c >= '0' && c <= '9';

    return !cond1 && !cond2 && !cond3;
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    if (str == NULL)
        return NULL;
    if (is_lowercase(str[0]))
        str[0] -= 'a' - 'A';
    for (; str[i]; i++)
        if (is_eow(str[i - 1]) && is_lowercase(str[i]))
            str[i] -= 'a' - 'A';
    return str;
}
