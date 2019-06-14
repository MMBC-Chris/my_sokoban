/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** sokoban
*/

#include <ncurses.h>
#include "sokoban.h"
#include "my.h"

void print_map_ch(map_element_t elem)
{
    switch (elem) {
    case WALL:
        attron(COLOR_PAIR(2));
        addch('#');
        break;
    case SOLVED_BOX:
    case BOX:
    case STORAGE:
    case EMPTY:
        attron(COLOR_PAIR(1));
        addch(' ');
        break;
    default:
        break;
    }
}

void print_boxes_and_storage(map_t *map, int ox, int oy)
{
    int offset_x = ox - map->width / 2;
    int offset_y = oy - map->height / 2;
    int sx = 0;
    int sy = 0;

    attron(COLOR_PAIR(4));
    for (int i = 0; i < map->box_count; i++) {
        sx = map->storage_x[i];
        sy = map->storage_y[i];
        mvaddch(offset_y + sy, offset_x + sx, 'O');
    }
    attron(COLOR_PAIR(3));
    for (int i = 0; i < map->box_count; i++)
        mvaddch(offset_y + map->box_y[i], offset_x + map->box_x[i], 'X');
}

void print_map(map_t *map, int ox, int oy)
{
    int offset_x = ox - map->width / 2;
    int offset_y = oy - map->height / 2;

    if (LINES < map->height || COLS < map->width) {
        mvaddstr(LINES / 2, COLS / 2 - 13, "Please enlarge the terminal");
        return;
    }
    for (int i = 0; i < map->height; i++) {
        move(offset_y + i, offset_x);
        for (int j = 0; j < map->width; j++)
            print_map_ch(map->content[i][j]);
    }
    print_boxes_and_storage(map, ox, oy);
    attron(COLOR_PAIR(5));
    mvaddch(offset_y + map->player_y, offset_x + map->player_x, 'P');
    attron(COLOR_PAIR(7));
    refresh();
}

int run(map_t *map)
{
    int loop = 1;
    int win = 0;

    while (loop) {
        erase();
        print_map(map, COLS / 2, LINES / 2);
        loop = sokoban_events(map);
        win = game_status(map);
        if (win)
            loop = 0;
    }
    print_map(map, COLS / 2, LINES / 2);
    if (win == 2)
        return 0;
    return win;
}

int sokoban(char *map_file)
{
    map_pack_t *map_pack = load_pack(map_file);
    int exit_status = 0;

    initscr();
    init_my_colors();
    curs_set(0);
    raw();
    keypad(stdscr, TRUE);
    noecho();
    exit_status = main_menu(map_pack);
    destroy_pack(map_pack);
    endwin();
    return exit_status;
}
