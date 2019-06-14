/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** solo menu
*/

#include <ncurses.h>
#include "sokoban.h"

void print_solo_menu(int level_count, int id)
{
    erase();
    attron(COLOR_PAIR(3));
    mvaddstr(LINES / 2 - 3, COLS / 2 - 5, "my_sokoban");
    attron(COLOR_PAIR(4));
    mvprintw(LINES / 2 - 1, COLS / 2 - 8, "Level: (max:% 4d)", level_count);
    attron(COLOR_PAIR(5));
    mvprintw(LINES / 2, COLS / 2 - 2, "% 4d", id);
    attron(COLOR_PAIR(7));
    mvprintw(LINES / 2 + 1, COLS / 2 - 2, "Back");
}

void print_cursor_solo_menu(int pos)
{
    char c1 = pos ? '>' : '<';
    char c2 = pos ? '<' : '>';

    attron(COLOR_PAIR(1));
    mvaddch(LINES / 2 + pos, COLS / 2 - 4, c1);
    mvaddch(LINES / 2 + pos, COLS / 2 + 3, c2);
}

int solo_menu_event(int key, int *pos, int *id, map_pack_t *map_pack)
{
    int quit = 0;

    if (key == KEY_UP)
        *pos -= (*pos > 0);
    if (key == KEY_DOWN)
        *pos += (*pos < 1);
    if (key == KEY_LEFT)
        *id -= (*id > 0 && *pos == 0);
    if (key == KEY_RIGHT)
        *id += (*id < map_pack->map_count - 1 && *pos == 0);
    if (key == '\n') {
        if (*pos == 0) {
            run(map_pack->maps[*id]);
            reset_game(map_pack->maps[*id]);
        }
        if (*pos == 1)
            quit = 1;
    }
    return 1 - quit;
}

void print_map_preview(map_pack_t *map_pack, int id)
{
    int x = COLS / 2 + map_pack->maps[id]->width / 2 + 20;

    print_map(map_pack->maps[id], x, LINES / 2);
}

void solo_menu(map_pack_t *map_pack)
{
    int cursor_pos = 0;
    int level_id = 0;
    int key = 0;
    int loop = 1;

    while (loop) {
        print_solo_menu(map_pack->map_count, level_id + 1);
        print_cursor_solo_menu(cursor_pos);
        print_map_preview(map_pack, level_id);
        refresh();
        key = getch();
        loop = solo_menu_event(key, &cursor_pos, &level_id, map_pack);
    }
}
