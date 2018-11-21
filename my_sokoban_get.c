/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_get
*/

#include "my.h"

char **transform_2d(struct number *num, int lengthx)
{
    char **map_2d = malloc(sizeof(char *) * 1000 + 3);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    for (k = 0; num->buff[k] != '\0'; k++) {
        map_2d[k] = malloc(sizeof(char) * lengthx + 1);
    }
    for (i = 0; i < num->sb + 2; i++) {
        if (j == lengthx + 1) {
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
        if (map[i] == '\n')
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

int number_of_answer(char **map, struct length *len)
{
    int number = 0;

    for (int i = 0; i < len->lengthy; i++) {
        for (int j = 0; j < len->lengthx; j++) {
            if (map[i][j] == 'O')
                number++;
        }
    }
    return (number);
}

int number_of_cases(char **map, struct length *len)
{
    int number = 0;

    for (int i = 0; i < len->lengthy; i++) {
        for (int j = 0; j < len->lengthx; j++) {
            if (map[i][j] == 'X')
                number++;
        }
    }
    return (number);
}