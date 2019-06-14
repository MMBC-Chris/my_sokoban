/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** movement
*/

#include <ncurses.h>
#include "sokoban.h"

int check_box_move(map_t *map, int x, int y, int i)
{
    int px = map->player_x;
    int py = map->player_y;
    int mbx = px + 2 * x;
    int mby = py + 2 * y;

    if (map->box_x[i] != (px + x) || map->box_y[i] != (py + y))
        return 1;
    if (map->content[mby][mbx] == WALL)
        return 0;
    for (int j = 0; j < map->box_count; j++)
        if (map->box_x[j] == mbx && map->box_y[j] == mby)
            return 0;
    map->box_x[i] += x;
    map->box_y[i] += y;
    return 1;
}

void move_player(map_t *map, int x, int y)
{
    int move = 1;
    int px = map->player_x;
    int py = map->player_y;

    if (map->content[py + y][px + x] == WALL)
        return;
    for (int i = 0; i < map->box_count; i++) {
        move = check_box_move(map, x, y, i);
        if (!move)
            return;
    }
    map->player_x += x;
    map->player_y += y;
}

void event(map_t *map, int key)
{
    switch (key) {
    case KEY_LEFT:
        move_player(map, -1, 0);
        break;
    case KEY_RIGHT:
        move_player(map, 1, 0);
        break;
    case KEY_UP:
        move_player(map, 0, -1);
        break;
    case KEY_DOWN:
        move_player(map, 0, 1);
        break;
    case 32:
        reset_game(map);
        break;
    case 'o':
        map->ai_on = 1;
        generate_ai_moves(map);
    default:
        break;
    }
}
