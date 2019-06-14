/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** usage
*/

#include "my.h"

int usage(char **av)
{
    my_printf("USAGE\n\t%s map\n", *av);
    my_printf("DESCRIPTION\n");
    my_printf("\tmap\tfile representing the warehouse map, ");
    my_printf("containing '#' for walls,\n\t\t");
    my_printf("'P' for the player, 'X' for boxes and 'O' ");
    my_printf("for storage locations.\n");
    return 0;
}
