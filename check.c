/*
** EPITECH PROJECT, 2018
** sokoban
** File description:
** check map validity
*/

#include <stdlib.h>
#include "my.h"
#include "sokoban.h"

void ie_exit(void)
{
    my_errstr(TBRD "Error:" TRST " invalid map\n");
    exit(84);
}

int is_valid_char(char c)
{
    if (c == ' ' || c == '\n' || c == '#')
        return 1;
    if (c == 'X' || c == 'O' || c == 'P')
        return 1;
    return 0;
}

void check_map(char *filestr)
{
    int player_found = 0;
    int box_count = 0;
    int storage_count = 0;

    for (int i = 0; i < my_strlen(filestr); i++) {
        if (!is_valid_char(filestr[i]))
            ie_exit();
        if (filestr[i] == 'P' && !player_found)
            player_found = 1;
        else if (filestr[i] == 'P' && player_found)
            ie_exit();
        if (filestr[i] == 'O')
            storage_count++;
        if (filestr[i] == 'X')
            box_count++;
    }
    if (box_count != storage_count)
        ie_exit();
    if (!player_found)
        ie_exit();
}
