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
        addch('#');
        break;
    case BOX:
    case STORAGE:
    case EMPTY:
        addch(' ');
        break;
    default:
        break;
    }
}

void print_boxes_and_storage(map_t *map)
{
    int offset_x = COLS / 2 - map->width / 2;
    int offset_y = LINES / 2 - map->height / 2;
    int sx = 0;
    int sy = 0;

    for (int i = 0; i < map->box_count; i++) {
        sx = map->storage_x[i];
        sy = map->storage_y[i];
        mvaddch(offset_y + sy, offset_x + sx, 'O');
    }
    for (int i = 0; i < map->box_count; i++)
        mvaddch(offset_y + map->box_y[i], offset_x + map->box_x[i], 'X');
}

void print_map(map_t *map)
{
    int offset_x = COLS / 2 - map->width / 2;
    int offset_y = LINES / 2 - map->height / 2;

    if (LINES < map->height || COLS < map->width) {
        mvaddstr(LINES / 2, COLS / 2 - 13, "Please enlarge the terminal");
        return;
    }
    for (int i = 0; i < map->height; i++) {
        move(offset_y + i, offset_x);
        for (int j = 0; j < map->width; j++)
            print_map_ch(map->content[i][j]);
    }
    print_boxes_and_storage(map);
    mvaddch(offset_y + map->player_y, offset_x + map->player_x, 'P');
    refresh();
}

int run(map_t *map)
{
    int loop = 1;
    int key = 0;
    int win = 0;

    while (loop) {
        erase();
        print_map(map);
        key = getch();
        refresh();
        if (key == 113 || key == 273)
            loop = 0;
        event(map, key);
        win = game_status(map);
        if (win)
            loop = 0;
    }
    print_map(map);
    if (win == 2)
        return 0;
    return win;
}

int sokoban(char *map_name)
{
    map_t *map = load_map(map_name);
    int exit_status = 0;

    initscr();
    curs_set(0);
    raw();
    keypad(stdscr, TRUE);
    noecho();
    exit_status = run(map);
    destroy_map(map);
    endwin();
    return exit_status;
}
