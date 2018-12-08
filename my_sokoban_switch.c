/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_switch
*/

#include "my.h"

char **main_switcher(char **map_2d, struct position *pos,
struct number *num, struct length *len)
{
    clear();
    for (int i = 0; i < len->lengthy; i++)
        printw("%s", map_2d[i]);
    mvprintw(pos->rows, pos->columns, "P");
    refresh();
    map_2d = case_switcher(pos, num, map_2d, len);
    return (map_2d);
}

void left_main(char **map_2d, struct position *pos, struct number *num)
{
    if (map_2d[pos->rows][pos->columns - 1] == 'X') {
        if (map_2d[pos->rows][pos->columns - 2] == ' ') {
            left_main_check_last_pos(map_2d, pos, num);
        } else if (map_2d[pos->rows][pos->columns - 2] == 'O') {
            map_2d[pos->rows][pos->columns - 1] = ' ';
            map_2d[pos->rows][pos->columns - 2] = 'X';
            pos->columns--;
            num->numberZero--;
        }
    } else if (map_2d[pos->rows][pos->columns - 1] != '#') {
        pos->columns--;
    }
}

void right_main(char **map_2d, struct position *pos, struct number *num)
{
    if (map_2d[pos->rows][pos->columns + 1] == 'X') {
        if (map_2d[pos->rows][pos->columns + 2] == ' ') {
            right_main_check_last_pos(map_2d, pos, num);
        } else if (map_2d[pos->rows][pos->columns + 2] == 'O') {
            map_2d[pos->rows][pos->columns + 1] = ' ';
            map_2d[pos->rows][pos->columns + 2] = 'X';
            pos->columns++;
            num->numberZero--;
        }
    } else if (map_2d[pos->rows][pos->columns + 1] != '#') {
        pos->columns++;
    }
}

void up_main(char **map_2d, struct position *pos, struct number *num)
{
    if (map_2d[pos->rows - 1][pos->columns] == 'X') {
        if (map_2d[pos->rows - 2][pos->columns] == ' ') {
            up_main_check_last_pos(map_2d, pos, num);
        } else if (map_2d[pos->rows - 2][pos->columns] == 'O') {
            map_2d[pos->rows - 1][pos->columns] = ' ';
            map_2d[pos->rows - 2][pos->columns] = 'X';
            pos->rows--;
            num->numberZero--;
        }
    } else if (map_2d[pos->rows - 1][pos->columns] != '#') {
        pos->rows--;
    }
}

void down_main(char **map_2d, struct position *pos, struct number *num)
{
    if (map_2d[pos->rows + 1][pos->columns] == 'X') {
        if (map_2d[pos->rows + 2][pos->columns] == ' ') {
            down_main_check_last_pos(map_2d, pos, num);
        } else if (map_2d[pos->rows + 2][pos->columns] == 'O') {
            map_2d[pos->rows + 1][pos->columns] = ' ';
            map_2d[pos->rows + 2][pos->columns] = 'X';
            pos->rows++;
            num->numberZero--;
        }
    } else if (map_2d[pos->rows + 1][pos->columns] != '#') {
        pos->rows++;
    }
}