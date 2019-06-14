/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** map pack loading
*/

#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void load_maps(map_pack_t *map_pack, char **la)
{
    map_pack->map_count = 0;
    for (int i = 1; la[i]; i++)
        map_pack->map_count++;
    map_pack->maps = malloc(sizeof(map_t *) * map_pack->map_count);
    for (int i = 1; la[i]; i++)
        map_pack->maps[i - 1] = load_map(la[i]);
}

map_pack_t *load_pack(char const *pack_name)
{
    map_pack_t *map_pack = malloc(sizeof(map_pack_t));
    char *content = ftostr(pack_name);
    char **la = my_str_to_line_array(content);

    if (my_strcmp(*la, "pack_file")) {
        map_pack->map_count = 1;
        map_pack->maps = malloc(sizeof(map_t *));
        map_pack->maps[0] = load_map(pack_name);
    } else
        load_maps(map_pack, la);
    free(content);
    for (int i = 0; la[i]; i++)
        free(la[i]);
    free(la);
    return map_pack;
}

void destroy_pack(map_pack_t *map_pack)
{
    for (int i = 0; i < map_pack->map_count; i++)
        destroy_map(map_pack->maps[i]);
    free(map_pack->maps);
    free(map_pack);
}
