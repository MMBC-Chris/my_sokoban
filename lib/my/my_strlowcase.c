/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strupcase
*/

#include <stdlib.h>

char *my_strlowcase(char *str)
{
    int i = 0;

    if (str == NULL)
        return NULL;
    for (; str[i]; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
    return str;
}
