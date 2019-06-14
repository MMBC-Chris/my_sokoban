/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** box management
*/

#include <stdlib.h>
#include "sokoban.h"
#include "my.h"

int count_boxes(map_element_t *line, int width)
{
    int count = 0;

    for (int i = 0; i < width; i++)
        if (line[i] == BOX || line[i] == SOLVED_BOX)
            count++;
    return count;
}

int init_boxes_line(map_t *map, int y, int box_iterator)
{
    for (int x = 0; x < map->width; x++) {
        if (map->content[y][x] == BOX || map->content[y][x] == SOLVED_BOX) {
            map->box_x[box_iterator] = x;
            map->box_y[box_iterator] = y;
            box_iterator++;
        }
    }
    return box_iterator;
}

int init_storage_line(map_t *map, int y, int storage_iterator)
{
    for (int x = 0; x < map->width; x++) {
        if (map->content[y][x] == STORAGE || map->content[y][x] == SOLVED_BOX) {
            map->storage_x[storage_iterator] = x;
            map->storage_y[storage_iterator] = y;
            storage_iterator++;
        }
    }
    return storage_iterator;
}

void init_boxes(map_t *map)
{
    int box_iterator = 0;
    int storage_iterator = 0;

    map->box_count = 0;
    for (int y = 0; y < map->height; y++)
        map->box_count += count_boxes(map->content[y], map->width);
    map->box_x = my_calloc(sizeof(int), map->box_count);
    map->box_y = my_calloc(sizeof(int), map->box_count);
    map->storage_x = my_calloc(sizeof(int), map->box_count);
    map->storage_y = my_calloc(sizeof(int), map->box_count);
    for (int y = 0; y < map->height; y++) {
        box_iterator = init_boxes_line(map, y, box_iterator);
        storage_iterator = init_storage_line(map, y, storage_iterator);
    }
}
