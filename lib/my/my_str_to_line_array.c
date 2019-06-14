/*
** EPITECH PROJECT, 2018
** lib
** File description:
** str to line array
*/

#include <stdlib.h>
#include "my.h"

int my_strllen(char const *str)
{
    int i;

    for (i = 0; str[i] && str[i] != '\n'; i++);
    return i;
}

char *my_strldup(char const *str)
{
	int len = my_strllen(str);
    char *dup = malloc(sizeof(char) * (len + 1));

    dup[len] = '\0';
    for (int i = 0; i < len; i++)
        dup[i] = str[i];
    return dup;
}

char **my_str_to_line_array(char const *str)
{
    char **arr;
    int count = 0;
    int offset = 0;

    for (int i = 0; str[i]; i++)
        if (str[i] == '\n')
            count++;
    arr = malloc(sizeof(char **) * (count + 1));
    arr[count] = NULL;
    for (int i = 0; i < count; i++) {
        arr[i] = my_strldup(str + offset);
        offset += my_strlen(arr[i]) + 1;
    }
    return arr;
}
