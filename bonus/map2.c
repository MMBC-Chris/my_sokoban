/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** map loading part 2
*/

#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void init_additionnal_map_info(map_t *map, char const *filecontent)
{
    map->ai_on = 0;
    map->ai_moves = NULL;
    map->string_content = my_strdup(filecontent);
}

map_t *load_map_from_string(char *str)
{
    map_t *map = malloc(sizeof(map_t));
    char **arr = my_str_to_line_array(str);
    int w = 0;
    int mw = 0;

    check_map(str);
    for (int i = 0; arr[i]; i++, w++)
        if (my_strlen(arr[i]) > mw)
            mw = my_strlen(arr[i]);
    map->width = mw;
    map->height = w;
    init_additionnal_map_info(map, str);
    init_map_and_player(arr, map);
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
    init_boxes(map);
    return map;
}
