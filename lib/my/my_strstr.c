/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** my_strstr
*/

#include <stdlib.h>

int compare(char const *s1, char const *s2)
{
    int i = 0;

    for (; s2[i]; i++) {
        if (s1[i] != s2[i])
            return 0;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    char *s = str;
    int found = 0;

    if (str == NULL || to_find == NULL)
        return NULL;
    for (; *s && !found; s++) {
        found = compare(s, to_find);
    }
    if (*to_find == '\0')
        return NULL;
    return found ? --s : NULL;
}
