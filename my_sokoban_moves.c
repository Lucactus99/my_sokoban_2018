/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** d
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char **case_switch(struct position *pos,
struct number *num, char **map_2d, struct length *len)
{
    switch(getch()) {
        case KEY_LEFT:
            left_main(map_2d, pos, num);
            break;
        case KEY_RIGHT:
            right_main(map_2d, pos, num);
            break;
        case KEY_UP:
            up_main(map_2d, pos, num);
            break;
        case KEY_DOWN:
            down_main(map_2d, pos, num);
            break;
        case ' ':
            map_2d = restart_game(pos, num, map_2d, len);
            break;
        default:
            break;
    }
    return (map_2d);
}

int check_moves_2(char **map, struct position *pos, int direction)
{
    if (direction == 2) {
        if ((map[pos->rows - 2][pos->columns] == '#' &&
        map[pos->rows - 1][pos->columns - 1] == '#') ||
        (map[pos->rows - 2][pos->columns] == '#' &&
        map[pos->rows - 1][pos->columns + 1] == '#')) {
            return (1);
        }
    }
    if (direction == 3) {
        if ((map[pos->rows + 2][pos->columns] == '#' &&
        map[pos->rows + 1][pos->columns - 1] == '#') ||
        (map[pos->rows + 2][pos->columns] == '#' &&
        map[pos->rows + 1][pos->columns + 1] == '#')) {
            return (1);
        }
    }
    return (0);
}

int check_moves_1(char **map, struct position *pos, int direction)
{
    if (direction == 0) {
        if ((map[pos->rows][pos->columns - 2] == '#' &&
        map[pos->rows - 1][pos->columns - 1] == '#') ||
        (map[pos->rows][pos->columns - 2] == '#' &&
        map[pos->rows + 1][pos->columns - 1] == '#')) {
            return (1);
        }
    }
    if (direction == 1) {
        if ((map[pos->rows][pos->columns + 2] == '#' &&
        map[pos->rows - 1][pos->columns + 1] == '#') ||
        (map[pos->rows][pos->columns + 2] == '#' &&
        map[pos->rows + 1][pos->columns + 1] == '#')) {
            return (1);
        }
    }
    return (0);
}

int find_pos_player(char **map, struct length *len, struct position *pos)
{
    for (int i = 0; i < len->lengthy; i++) {
        for (int j = 0; j < len->lengthx; j++) {
            if (map[i][j] == 'P') {
                pos->rows = i;
                pos->columns = j;
                return (0);
            }
        }
    }
    return (84);
}