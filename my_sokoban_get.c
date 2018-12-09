/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_get
*/

#include "my.h"

void initiate_varia(struct position *pos, struct number *num,
char **map_2d, struct length *len)
{
    pos->rows = 1;
    pos->columns = 1;
    num->numberZero = number_of_answer(map_2d, len, pos);
    num->numberZeroConst = number_of_answer(map_2d, len, pos);
    num->numberCase = number_of_cases(map_2d, len);
}

char **case_switcher(struct position *pos,
struct number *num, char **map_2d, struct length *len)
{
    switch (getch()) {
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

char **transform_2d(struct number *num, struct length *len)
{
    char **map_2d = malloc(sizeof(char *) * (len->lengthy + 1));
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    for (k = 0; k < len->lengthy + 1; k++) {
        map_2d[k] = malloc(sizeof(char) * (len->lengthx + 1));
    }
    for (i = 0; i < num->sb; i++) {
        if (j == len->lengthx + 1) {
            j = 0;
            l++;
        }
        map_2d[l][j] = num->buff[i];
        j++;
    }
    return (map_2d);
}

int length_map_y(char *map)
{
    int length = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        length++;
    }
    return (length);
}

int length_map_x(char *map)
{
    int length = 0;

    for (int i = 0; map[i] != '\n'; i++)
        length++;
    return (length);
}