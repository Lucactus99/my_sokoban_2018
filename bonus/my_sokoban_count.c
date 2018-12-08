/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_count
*/

#include "my.h"

int number_of_answer_y(char **map, struct length *len, int number, int i)
{
    for (int j = 0; j < len->lengthx; j++) {
        if (map[i][j] == 'O') {
            number++;
        }
    }
    return (number);
}

int number_of_answer(char **map, struct length *len, struct position *pos)
{
    int number = 0;
    int tmp = 0;

    for (int i = 0; i < len->lengthy; i++) {
        number = number_of_answer_y(map, len, number, i);
    }
    pos->answery = malloc(sizeof(int) * number);
    pos->answerx = malloc(sizeof(int) * number);
    for (int i = 0; i < len->lengthy; i++) {
        for (int j = 0; j < len->lengthx; j++) {
            if (map[i][j] == 'O') {
                pos->answery[tmp] = i;
                pos->answerx[tmp] = j;
                tmp++;
            }
        }
    }
    return (number);
}

int number_of_cases_y(char **map, struct length *len, int number, int i)
{
    for (int j = 0; j < len->lengthx; j++) {
        if (map[i][j] == 'X')
            number++;
    }
    return (number);
}

int number_of_cases(char **map, struct length *len)
{
    int number = 0;

    for (int i = 0; i < len->lengthy; i++) {
        number = number_of_cases_y(map, len, number, i);
    }
    return (number);
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