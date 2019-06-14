/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** sokoban 
*/

#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "sokoban.h"

int sokoban_events(map_t *map)
{
    int key = 0;
    int loop = 1;

    if (!map->ai_on) {
        key = getch();
        if (key == 'q')
            loop = 0;
        event(map, key);
    } else {
        if (map->ai_moves[map->ai_move_counter] == 'a')
            event(map, KEY_UP);
        if (map->ai_moves[map->ai_move_counter] == 'b')
            event(map, KEY_RIGHT);
        if (map->ai_moves[map->ai_move_counter] == 'c')
            event(map, KEY_DOWN);
        if (map->ai_moves[map->ai_move_counter] == 'd')
            event(map, KEY_LEFT);
        map->ai_move_counter++;
        usleep(100000);
    }
    return loop;
}
