/*
** EPITECH PROJECT, 2018
** Day
** File description:
** strcat
*/

#include <stdlib.h>

int my_strlen(char const *);

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int dest_len = 0;

    if (src == NULL || dest == NULL)
        return NULL;
    dest_len = my_strlen(dest);
    for (; src[i]; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';
    return dest;
}
