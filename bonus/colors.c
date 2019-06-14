/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** color management
*/

#include <ncurses.h>
#include "sokoban.h"

void init_my_colors(void)
{
    start_color();
    init_color(COLOR_BLACK, 0, 0, 0);
    bkgd(COLOR_BLACK);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);
}
