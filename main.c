/*
** EPITECH PROJECT, 2018
** Project Name
** File description:
** my_popup
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

char **transform_2d(char *map, int sb, int lengthx)
{
    char **map_2d = malloc(sizeof(char *) * 1000 + 3);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    for (k = 0; map[k] != '\0'; k++) {
        map_2d[k] = malloc(sizeof(char) * lengthx + 1);
    }
    for (i = 0; i < sb + 2; i++) {
        if (j == lengthx + 1) {
            j = 0;
            l++;
        }
        map_2d[l][j] = map[i];
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

int number_of_answer(char **map, int lengthy, int lengthx)
{
    int number = 0;

    for (int i = 0; i < lengthy; i++) {
        for (int j = 0; j < lengthx; j++) {
            if (map[i][j] == 'O')
                number++;
        }
    }
    return (number);
}

int number_of_cases(char **map, int lengthy, int lengthx)
{
    int number = 0;

    for (int i = 0; i < lengthy; i++) {
        for (int j = 0; j < lengthx; j++) {
            if (map[i][j] == 'X')
                number++;
        }
    }
    return (number);
}

int check_moves_2(char **map, int rows, int columns, int direction)
{
    if (direction == 2) {
        if ((map[rows - 2][columns] == '#' &&
        map[rows - 1][columns - 1] == '#') ||
        (map[rows - 2][columns] == '#' &&
        map[rows - 1][columns + 1] == '#')) {
            return (1);
        }
    }
    if (direction == 3) {
        if ((map[rows + 2][columns] == '#' &&
        map[rows + 1][columns - 1] == '#') ||
        (map[rows + 2][columns] == '#' &&
        map[rows + 1][columns + 1] == '#')) {
            return (1);
        }
    }
    return (0);
}

int check_moves_1(char **map, int rows, int columns, int direction)
{
    if (direction == 0) {
        if ((map[rows][columns - 2] == '#' &&
        map[rows - 1][columns - 1] == '#') ||
        (map[rows][columns - 2] == '#' &&
        map[rows + 1][columns - 1] == '#')) {
            return (1);
        }
    }
    if (direction == 1) {
        if ((map[rows][columns + 2] == '#' &&
        map[rows - 1][columns + 1] == '#') ||
        (map[rows][columns + 2] == '#' &&
        map[rows + 1][columns + 1] == '#')) {
            return (1);
        }
    }
    return (0);
}

int main_loop(int lengthy, int lengthx, char *buff, int sb)
{
    char **map_2d = transform_2d(buff, sb, lengthx);
    int tmpPosy = 0;
    int tmpPosx = 0;
    int rows = 1;
    int columns = 1;
    int c;
    int numberZero = number_of_answer(map_2d, lengthy, lengthx);
    int numberCase = number_of_cases(map_2d, lengthy, lengthx);

    while (numberZero > 0 && numberCase > 0) {
        clear();
        for (int i = 0; i < lengthy; i++)
            printw("%s", map_2d[i]);
        mvprintw(rows, columns, "P");
        refresh();
        c = getch();
        switch(c)
        {
            case KEY_LEFT:
                if (map_2d[rows][columns - 1] == 'X') {
                    if (map_2d[rows][columns - 2] == ' ') {
                        if (tmpPosy == rows && tmpPosx == columns - 1) {
                            numberZero++;
                            map_2d[rows][columns - 1] = 'O';
                        }
                        else
                            map_2d[rows][columns - 1] = ' ';
                        map_2d[rows][columns - 2] = 'X';
                        columns--;
                        numberCase -= check_moves_1(map_2d, rows, columns, 0);
                    } else if (map_2d[rows][columns - 2] == 'O') {
                        map_2d[rows][columns - 1] = ' ';
                        map_2d[rows][columns - 2] = 'X';
                        columns--;
                        tmpPosy = rows;
                        tmpPosx = columns - 1;
                        numberZero--;
                    }
                } else if (map_2d[rows][columns - 1] != '#') {
                    columns--;
                }
                break;
            case KEY_RIGHT:
                if (map_2d[rows][columns + 1] == 'X') {
                    if (map_2d[rows][columns + 2] == ' ') {
                        if (tmpPosy == rows && tmpPosx == columns + 1) {
                            numberZero++;
                            map_2d[rows][columns + 1] = 'O';
                        }
                        else
                            map_2d[rows][columns + 1] = ' ';
                        map_2d[rows][columns + 2] = 'X';
                        columns++;
                        numberCase -= check_moves_1(map_2d, rows, columns, 1);
                    } else if (map_2d[rows][columns + 2] == 'O') {
                        map_2d[rows][columns + 1] = ' ';
                        map_2d[rows][columns + 2] = 'X';
                        columns++;
                        tmpPosy = rows;
                        tmpPosx = columns + 1;
                        numberZero--;
                    }
                } else if (map_2d[rows][columns + 1] != '#') {
                    columns++;
                }
                break;
            case KEY_UP:
                if (map_2d[rows - 1][columns] == 'X') {
                    if (map_2d[rows - 2][columns] == ' ') {
                        if (tmpPosy == rows - 1 && tmpPosx == columns) {
                            numberZero++;
                            map_2d[rows - 1][columns] = 'O';
                        }
                        else
                            map_2d[rows - 1][columns] = ' ';
                        map_2d[rows - 2][columns] = 'X';
                        rows--;
                        numberCase -= check_moves_2(map_2d, rows, columns, 2);
                    } else if (map_2d[rows - 2][columns] == 'O') {
                        map_2d[rows - 1][columns] = ' ';
                        map_2d[rows - 2][columns] = 'X';
                        rows--;
                        tmpPosy = rows - 1;
                        tmpPosx = columns;
                        numberZero--;
                    }
                } else if (map_2d[rows - 1][columns] != '#') {
                    rows--;
                }
                break;
            case KEY_DOWN:
                if (map_2d[rows + 1][columns] == 'X') {
                    if (map_2d[rows + 2][columns] == ' ') {
                        if (tmpPosy == rows + 1 && tmpPosx == columns) {
                            numberZero++;
                            map_2d[rows + 1][columns] = 'O';
                        }
                        else
                            map_2d[rows + 1][columns] = ' ';
                        map_2d[rows + 2][columns] = 'X';
                        rows++;
                        numberCase -= check_moves_2(map_2d, rows, columns, 3);
                    } else if (map_2d[rows + 2][columns] == 'O') {
                        map_2d[rows + 1][columns] = ' ';
                        map_2d[rows + 2][columns] = 'X';
                        rows++;
                        tmpPosy = rows + 1;
                        tmpPosx = columns;
                        numberZero--;
                    }
                } else if (map_2d[rows + 1][columns] != '#') {
                    rows++;
                }
                break;
            case ' ':
                rows = 1;
                columns = 1;
                numberZero = number_of_answer(map_2d, lengthy, lengthx);
                numberCase = number_of_cases(map_2d, lengthy, lengthx);
                map_2d = transform_2d(buff, sb, lengthx);
            default:
                break;
        }
    }
    if (numberCase == 0)
        return (1);
    return (0);
}

int my_sokoban(char *buff, int sb)
{
    int lengthx = length_map_x(buff);
    int lengthy = length_map_y(buff);
    int value;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    value = main_loop(lengthy, lengthx, buff, sb);
    endwin();
    return (value);
;}

int main(int ac, char **av)
{
    int size = 0;
    int fd;
    char *buff = malloc(sizeof(char) * 1000 + 2);

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd == - 1) {
        my_putstr("Error with opn\n");
        return (84);
    }
    size = read(fd, buff, 1000);
    return (my_sokoban(buff, 1000));
}