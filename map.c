/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** map loading
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "sokoban.h"

map_element_t ctoelem(char c)
{
    switch (c) {
    case '#':
        return WALL;
    case 'O':
        return STORAGE;
    case 'X':
        return BOX;
    case 'P':
    case ' ':
        return EMPTY;
    default:
        return NONE;
    }
}

void find_player_pos(map_t *map, char **content, int y)
{
    for (int x = 0; content[y][x]; x++)
        if (content[y][x] == 'P') {
            map->player_x = x;
            map->player_y = y;
            map->init_player_x = x;
            map->init_player_y = y;
        }
}

void init_map_and_player(char **content, map_t *map)
{
    map->content = malloc(sizeof(map_element_t *) * map->height);
    map->reset = malloc(sizeof(map_element_t *) * map->height);
    for (int i = 0; i < map->height; i++) {
        map->content[i] = malloc(sizeof(map_element_t) * map->width);
        map->reset[i] = malloc(sizeof(map_element_t) * map->width);
    }
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < map->width; j++)
            map->content[i][j] = EMPTY;
    for (int i = 0; i < map->height; i++)
        for (int j = 0; j < my_strlen(content[i]); j++) {
            map->content[i][j] = ctoelem(content[i][j]);
            map->reset[i][j] = ctoelem(content[i][j]);
        }
    for (int i = 0; i < map->height; i++)
        find_player_pos(map, content, i);
}

map_t *load_map(char const *filename)
{
    map_t *map = malloc(sizeof(map_t));
    char *filecontent = ftostr(filename);
    char **arr = my_str_to_line_array(filecontent);
    int w = 0;
    int mw = 0;

    check_map(filecontent);
    for (int i = 0; arr[i]; i++, w++)
        if (my_strlen(arr[i]) > mw)
            mw = my_strlen(arr[i]);
    map->width = mw;
    map->height = w;
    init_map_and_player(arr, map);
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    init_boxes(map);
    free(filecontent);
    return map;
}

void destroy_map(map_t *map)
{
    for (int i = 0; i < map->height; i++) {
        free(map->content[i]);
        free(map->reset[i]);
    }
    free(map->content);
    free(map->reset);
    free(map->box_x);
    free(map->box_y);
    free(map->storage_x);
    free(map->storage_y);
    free(map);
}
