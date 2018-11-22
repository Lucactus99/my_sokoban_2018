/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_get
*/

#include "my.h"

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