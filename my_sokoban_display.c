/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_display
*/

#include "my.h"

void left_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    if (pos->tmpPosy == pos->rows && pos->tmpPosx == pos->columns - 1) {
        num->numberZero++;
        map_2d[pos->rows][pos->columns - 1] = 'O';
    }
    else
        map_2d[pos->rows][pos->columns - 1] = ' ';
    map_2d[pos->rows][pos->columns - 2] = 'X';
    pos->columns--;
    num->numberCase -= check_moves_left(map_2d, pos);
}

void right_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    if (pos->tmpPosy == pos->rows && pos->tmpPosx == pos->columns + 1) {
        num->numberZero++;
        map_2d[pos->rows][pos->columns + 1] = 'O';
    }
    else
        map_2d[pos->rows][pos->columns + 1] = ' ';
    map_2d[pos->rows][pos->columns + 2] = 'X';
    pos->columns++;
    num->numberCase -= check_moves_right(map_2d, pos);
}

void up_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    if (pos->tmpPosy == pos->rows - 1 && pos->tmpPosx == pos->columns) {
        num->numberZero++;
        map_2d[pos->rows - 1][pos->columns] = 'O';
    }
    else
        map_2d[pos->rows - 1][pos->columns] = ' ';
    map_2d[pos->rows - 2][pos->columns] = 'X';
    pos->rows--;
    num->numberCase -= check_moves_up(map_2d, pos);
}

void down_main_check_last_pos(char **map_2d, struct position *pos,
struct number *num)
{
    if (pos->tmpPosy == pos->rows + 1 && pos->tmpPosx == pos->columns) {
        num->numberZero++;
        map_2d[pos->rows + 1][pos->columns] = 'O';
    }
    else
        map_2d[pos->rows + 1][pos->columns] = ' ';
    map_2d[pos->rows + 2][pos->columns] = 'X';
    pos->rows++;
    num->numberCase -= check_moves_down(map_2d, pos);
}

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