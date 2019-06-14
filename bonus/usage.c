/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** usage
*/

#include <ncurses.h>
#include "my.h"

void get_help(void)
{
    erase();
    mvaddstr(LINES / 2 - 4, COLS / 2 - 22, "You are a warehouse keeper");
    addstr(", represented as a P.");
    mvaddstr(LINES / 2 - 3, COLS / 2 - 32, "Your goal is to push all the ");
    addstr("boxes (X) to the storage locations (O).");
    mvaddstr(LINES / 2 - 1, COLS / 2 - 27, "You win the game when all ");
    addstr("the boxes are on storage locations.");
    mvaddstr(LINES / 2, COLS / 2 - 23, "You lose when you cannot ");
    addstr("move any box anymore.");
    mvaddstr(LINES / 2 + 1, COLS / 2 - 23, "You can move your player ");
    addstr("with the arrow keys,");
    mvaddstr(LINES / 2 + 2, COLS / 2 - 17, "Reset the game with the spacebar,");
    mvaddstr(LINES / 2 + 3, COLS / 2 - 8, "and quit with q.");
    refresh();
    getch();
}

int usage(char **av)
{
    my_printf("USAGE\n\t%s map\n", *av);
    my_printf("DESCRIPTION\n");
    my_printf("\tmap\tfile representing the warehouse map, ");
    my_printf("containing '#' for walls,\n\t\t");
    my_printf("'P' for the player, 'X' for boxes, 'O' ");
    my_printf("for storage locations and 'S' for boxes ");
    my_printf("situated on storage locations\n");
    return 0;
}
