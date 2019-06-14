/*
** EPITECH PROJECT, 2018
** Day
** File description:
** strcat
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int dest_len = 0;

    if (src == NULL || dest == NULL || n < 0)
        return NULL;
    dest_len = my_strlen(dest);
    for (; src[i] && i < n; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
