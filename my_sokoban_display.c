/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** d
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
    num->numberCase -= check_moves_1(map_2d, pos, 0);
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
    num->numberCase -= check_moves_1(map_2d, pos, 1);
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
    num->numberCase -= check_moves_2(map_2d, pos, 2);
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
    num->numberCase -= check_moves_2(map_2d, pos, 3);
}

char **restart_game(struct position *pos,
struct number *num, char **map_2d, struct length *len)
{
    map_2d = transform_2d(num, len->lengthx);
    num->numberZero = number_of_answer(map_2d, len);
    num->numberCase = number_of_cases(map_2d, len);
    find_pos_player(map_2d, len, pos);
    map_2d[pos->rows][pos->columns] = ' ';
    return (map_2d);
}