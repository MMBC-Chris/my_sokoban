/*
** EPITECH PROJECT, 2018
** Day08
** File description:
** strdup
*/

#include <stdlib.h>

int my_strlen(char const *);
char *my_strcpy(char *, char const *);

char *my_strdup(char const *str)
{
    char *dest = malloc(sizeof(char) * (my_strlen(str) + 1));

    my_strcpy(dest, str);
    return dest;
}
