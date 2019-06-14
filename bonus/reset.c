/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** reset game
*/

#include <stdlib.h>
#include "sokoban.h"

void reset_game(map_t *map)
{
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < map->width; j++)
            map->content[i][j] = map->reset[i][j];
    free(map->box_x);
    free(map->box_y);
    free(map->storage_x);
    free(map->storage_y);
    init_boxes(map);
    map->player_x = map->init_player_x;
    map->player_y = map->init_player_y;
}
