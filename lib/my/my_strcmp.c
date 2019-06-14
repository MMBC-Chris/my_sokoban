/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strcmp
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return 0;
    while (s1[i] && (s1[i] == s2[i]))
        i++;
    return s1[i] - s2[i];
}
