/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** ai
*/

#include <stdlib.h>
#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

int unnecessary_move(char *moves, int i)
{
    if (i == 0)
        return 0;
    if (moves[i] == 'e')
        return 0;
    if (moves[i - 1] == 'a')
        return moves[i] == 'c';
    if (moves[i - 1] == 'b')
        return moves[i] == 'd';
    if (moves[i - 1] == 'c')
        return moves[i] == 'a';
    if (moves[i - 1] == 'd')
        return moves[i] == 'b';
    return 0;
}

void next_move(char **moves)
{
    int move_count = my_strlen(*moves);
    char *new_moves = NULL;
    int ntc = 1;

    for (int i = move_count - 1; i >= 0 && ntc; i--) {
        moves[0][i]++;
        if (unnecessary_move(*moves, i))
            moves[0][i]++;
        if (moves[0][i] > 'd')
            moves[0][i] -= 4;
        else
            ntc = 0;
    }
    if (ntc) {
        new_moves = malloc(sizeof(char) * (move_count + 2));
        my_strcpy(new_moves + 1, *moves);
        *new_moves = 'a';
        free(*moves);
        *moves = new_moves;
    }
}

int test_win(map_t *map)
{
    map_t *ai_map = load_map_from_string(map->string_content);
    int dx;
    int dy;
    char c;
    int win = 0;

    for (int i = 0; map->ai_moves[i]; i++) {
        c = map->ai_moves[i];
        dx = -((c - 'a') % 2 * ((c - 'a') - 2));
        dy = (c - 'a' + 1) % 2 * ((c - 'a') - 1);
        move_player(ai_map, dx, dy);
    }
    win = game_status(ai_map);
    destroy_map(ai_map);
    if (win == 2)
        return 1;
    return 0;
}

void generate_ai_moves(map_t *map)
{
    int win = 0;
    
    map->ai_moves = my_strdup("a");
    while (!win) {
        win = test_win(map);
        if (!win)
            next_move(&map->ai_moves);
    }
    mvprintw(0, 0, "Final solution: %s", map->ai_moves);
    refresh();
    getch();
    map->ai_move_counter = 0;
}
