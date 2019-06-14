/*
** EPITECH PROJECT, 2018
** my sokoban
** File description:
** main
*/

#include "my.h"
#include "sokoban.h"

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h"))
        return usage(av);
    else if (ac == 2)
        return sokoban(av[1]);
    else
        return 84;
}
