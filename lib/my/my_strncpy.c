/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strncpy
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (src == NULL || dest == NULL)
        return NULL;
    while (src[i] && i < n) {
        dest[i] = src[i];
        i++;
    }
    while (i < n) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
