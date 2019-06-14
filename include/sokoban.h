/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** sokoban
*/

#ifndef _SOKOBAN_H_
#define _SOKOBAN_H_

typedef enum
{
    NONE,
    EMPTY,
    WALL,
    STORAGE,
    BOX
} map_element_t;

typedef struct
{
    int width;
    int height;
    map_element_t **content;
    map_element_t **reset;
    int player_x;
    int player_y;
    int init_player_x;
    int init_player_y;
    int box_count;
    int *box_x;
    int *box_y;
    int *storage_x;
    int *storage_y;
} map_t;

int usage(char **);
int sokoban(char *);

map_t *load_map(char const *);
void destroy_map(map_t *);

void init_boxes(map_t *);

void event(map_t *, int);

int game_status(map_t *);

void reset_game(map_t *);

void check_map(char *);

#endif
