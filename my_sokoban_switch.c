/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** d
*/

#include "my.h"

void left_main(char **map_2d, struct position *pos, struct number *num)
{
    if (map_2d[pos->rows][pos->columns - 1] == 'X') {
        if (map_2d[pos->rows][pos->columns - 2] == ' ') {
            left_main_check_last_pos(map_2d, pos, num);
        } else if (map_2d[pos->rows][pos->columns - 2] == 'O') {
            map_2d[pos->rows][pos->columns - 1] = ' ';
            map_2d[pos->rows][pos->columns - 2] = 'X';
            pos->columns--;
            pos->tmpPosy = pos->rows;
            pos->tmpPosx = pos->columns - 1;
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
            pos->tmpPosy = pos->rows;
            pos->tmpPosx = pos->columns + 1;
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
            pos->tmpPosy = pos->rows - 1;
            pos->tmpPosx = pos->columns;
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
            pos->tmpPosy = pos->rows + 1;
            pos->tmpPosx = pos->columns;
            num->numberZero--;
        }
    } else if (map_2d[pos->rows + 1][pos->columns] != '#') {
        pos->rows++;
    }
}