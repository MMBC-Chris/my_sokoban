/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** strcmp
*/

#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL || n == 0)
        return 0;
    while (s1[i] && n && (s1[i] == s2[i])) {
        i++;
        n--;
    }
    if (!n)
        return 0;
    return s1[i] - s2[i];
}
