/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_moves
*/

#include "my.h"

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

int check_moves_left(char **map, struct position *pos)
{
    if (map[pos->rows][pos->columns - 2] == '#' &&
    map[pos->rows - 1][pos->columns - 1] == 'X' &&
    map[pos->rows - 1][pos->columns - 2] == '#')
        return (2);
    if (map[pos->rows][pos->columns - 2] == '#' &&
    map[pos->rows + 1][pos->columns - 1] == 'X' &&
    map[pos->rows + 1][pos->columns - 2] == '#')
        return (2);
    if ((map[pos->rows][pos->columns - 2] == '#' &&
    (map[pos->rows - 1][pos->columns - 1] == '#' ||
    map[pos->rows - 1][pos->columns - 1] == 'X')) ||
    (map[pos->rows][pos->columns - 2] == '#' &&
    (map[pos->rows + 1][pos->columns - 1] == '#' ||
    map[pos->rows + 1][pos->columns - 1] == 'X')))
        return (1);
    return (0);
}

int check_moves_right(char **map, struct position *pos)
{
    if (map[pos->rows][pos->columns + 2] == '#' &&
    map[pos->rows - 1][pos->columns + 1] == 'X' &&
    map[pos->rows - 1][pos->columns + 2] == '#')
        return (2);
    if (map[pos->rows][pos->columns + 2] == '#' &&
    map[pos->rows + 1][pos->columns + 1] == 'X' &&
    map[pos->rows + 1][pos->columns + 2] == '#')
        return (2);
    if ((map[pos->rows][pos->columns + 2] == '#' &&
    (map[pos->rows - 1][pos->columns + 1] == '#' ||
    map[pos->rows - 1][pos->columns + 1] == 'X')) ||
    (map[pos->rows][pos->columns + 2] == '#' &&
    (map[pos->rows + 1][pos->columns + 1] == '#' ||
    map[pos->rows + 1][pos->columns + 1] == 'X')))
        return (1);
    return (0);
}

int check_moves_up(char **map, struct position *pos)
{
    if (map[pos->rows - 2][pos->columns] == '#' &&
    map[pos->rows - 1][pos->columns - 1] == 'X' &&
    map[pos->rows - 2][pos->columns - 1] == '#')
        return (2);
    if (map[pos->rows - 2][pos->columns] == '#' &&
    map[pos->rows + 1][pos->columns - 1] == 'X' &&
    map[pos->rows - 2][pos->columns + 1] == '#')
        return (2);
    if ((map[pos->rows - 2][pos->columns] == '#' &&
    (map[pos->rows - 1][pos->columns - 1] == '#' ||
    map[pos->rows - 1][pos->columns - 1] == 'X')) ||
    (map[pos->rows - 2][pos->columns] == '#' &&
    (map[pos->rows - 1][pos->columns + 1] == '#' ||
    map[pos->rows - 1][pos->columns + 1] == 'X')))
        return (1);
    return (0);
}

int check_moves_down(char **map, struct position *pos)
{
    if (map[pos->rows + 2][pos->columns] == '#' &&
    map[pos->rows - 1][pos->columns + 1] == 'X' &&
    map[pos->rows + 2][pos->columns - 1] == '#')
        return (2);
    if (map[pos->rows + 2][pos->columns] == '#' &&
    map[pos->rows + 1][pos->columns + 1] == 'X' &&
    map[pos->rows + 2][pos->columns + 1] == '#')
        return (2);
    if ((map[pos->rows + 2][pos->columns] == '#' &&
    (map[pos->rows + 1][pos->columns - 1] == '#' ||
    map[pos->rows + 1][pos->columns - 1] == 'X')) ||
    (map[pos->rows + 2][pos->columns] == '#' &&
    (map[pos->rows + 1][pos->columns + 1] == '#' ||
    map[pos->rows + 1][pos->columns + 1] == 'X')))
        return (1);
    return (0);
}