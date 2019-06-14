/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strcpy
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (src == NULL || dest == NULL)
        return NULL;
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
