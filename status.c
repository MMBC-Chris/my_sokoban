/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** win or lose detection
*/

#include "sokoban.h"

int box_solved(map_t *map, int box_nb)
{
    int bx = map->box_x[box_nb];
    int by = map->box_y[box_nb];

    for (int i = 0; i < map->box_count; i++) {
        if (map->storage_x[i] == bx && map->storage_y[i] == by)
            return 1;
    }
    return 0;
}

int box_blocked(map_t *map, int box_nb)
{
    int blocked = 0;
    int bx = map->box_x[box_nb];
    int by = map->box_y[box_nb];

    if (map->content[by - 1][bx] == WALL || map->content[by + 1][bx] == WALL)
        blocked++;
    if (map->content[by][bx - 1] == WALL || map->content[by][bx + 1] == WALL)
        blocked++;
    if (blocked == 2)
        return 1;
    else
        return 0;
}

int game_status(map_t *map)
{
    int win = 1;
    int lost = 1;

    for (int i = 0; i < map->box_count; i++)
        if (!box_solved(map, i))
            win = 0;
    for (int i = 0; i < map->box_count; i++)
        if (!box_blocked(map, i))
            lost = 0;
    if (win)
        return 2;
    if (lost)
        return 1;
    return 0;
}
