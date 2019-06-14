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
    BOX,
    SOLVED_BOX
} map_element_t;

typedef struct
{
    int width;
    int height;
    char *string_content;
    map_element_t **content;
    map_element_t **reset;
    int player_x;
    int player_y;
    int player2_x;
    int player2_y;
    int init_player_x;
    int init_player_y;
    int init_player2_x;
    int init_player2_y;
    int box_count;
    int *box_x;
    int *box_y;
    int *storage_x;
    int *storage_y;
    int ai_on;
    char *ai_moves;
    unsigned int ai_move_counter;
} map_t;

typedef struct
{
    int map_count;
    map_t **maps;
} map_pack_t;

int usage(char **);
int sokoban(char *);

map_t *load_map(char const *);
map_t *load_map_from_string(char *);
void init_map_and_player(char **, map_t *);
void init_additionnal_map_info(map_t *, char const *);
void destroy_map(map_t *);
void print_map(map_t *, int, int);
map_pack_t *load_pack(char const *);
void destroy_pack(map_pack_t *);
void init_boxes(map_t *);
int run(map_t *);
void event(map_t *, int);
void move_player(map_t *, int, int);
int sokoban_events(map_t *);
int game_status(map_t *);
void reset_game(map_t *);
void check_map(char *);
void init_my_colors(void);
int main_menu(map_pack_t *);
void solo_menu(map_pack_t *);
void get_help(void);
void print_solo_menu(int, int);
void print_cursor_solo_menu(int);
void print_map_preview(map_pack_t *, int);
void generate_ai_moves(map_t *);

#endif

