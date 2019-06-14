/*
** EPITECH PROJECT, 2018
** Day06
** File description:
** revstr
*/

char *my_revstr(char *str)
{
    int last = 0;
    int first = 0;
    char tmp = 0;

    while (str[last])
        last++;
    last--;
    while (first < last) {
        tmp = str[first];
        str[first] = str[last];
        str[last] = tmp;
        first++;
        last--;
    }
    return str;
}
