/*
** EPITECH PROJECT, 2018
** Day3
** File description:
** put char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_errchar(char c)
{
    write(2, &c, 1);
}
