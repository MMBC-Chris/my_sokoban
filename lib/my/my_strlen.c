/*
** EPITECH PROJECT, 2018
** Day04
** File description:
** computing string length
*/

int my_strlen(char const *s)
{
    int size = 0;

    while (s[size])
        size++;
    return size;
}
