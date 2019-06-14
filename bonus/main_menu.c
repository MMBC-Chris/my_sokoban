/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** main menu
*/

#include <ncurses.h>
#include "sokoban.h"

void print_main_menu(void)
{
    erase();
    attron(COLOR_PAIR(3));
    mvaddstr(LINES / 2 - 3, COLS / 2 - 5, "my_sokoban");
    attron(COLOR_PAIR(4));
    mvaddstr(LINES / 2 - 1, COLS / 2 - 2, "Solo");
    attron(COLOR_PAIR(5));
    mvaddstr(LINES / 2, COLS / 2 - 2, "Help");
    attron(COLOR_PAIR(7));
    mvaddstr(LINES / 2 + 1, COLS / 2 - 2, "Quit");
}

void print_cursor(int cursor_pos)
{
    attron(COLOR_PAIR(1));
    mvaddch(LINES / 2 - 1 + cursor_pos, COLS / 2 - 4, '>');
    mvaddch(LINES / 2 - 1 + cursor_pos, COLS / 2 + 3, '<');
}

int main_menu_event(int key, int *cursor_pos, map_pack_t *map_pack)
{
    int quit = 0;

    switch (key) {
    case KEY_UP:
        *cursor_pos -= (*cursor_pos > 0);
        break;
    case KEY_DOWN:
        *cursor_pos += (*cursor_pos < 2);
        break;
    case '\n':
        if (*cursor_pos == 0)
            solo_menu(map_pack);
        if (*cursor_pos == 1)
            get_help();
        if (*cursor_pos == 2)
            quit = 1;
    }
    return 1 - quit;
}

int main_menu(map_pack_t *map_pack)
{
    int loop = 1;
    int cursor_pos = 0;
    int key = 0;

    while (loop) {
        print_main_menu();
        print_cursor(cursor_pos);
        refresh();
        key = getch();
        loop = main_menu_event(key, &cursor_pos, map_pack);
    }
    return 0;
}
