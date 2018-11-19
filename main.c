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

char **transform_2d(char *map, struct stat sb, int lengthx)
{
    char **map_2d = malloc(sizeof(char *) * sb.st_size + 3);
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    for (k = 0; map[k] != '\0'; k++) {
        map_2d[k] = malloc(sizeof(char) * lengthx + 1);
    }
    for (i = 0; i < sb.st_size + 2; i++) {
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

int number_of_answer(char *map)
{
    int number = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'O')
            number++;
    }
    return (number);
}

int number_of_cases(char *map)
{
    int number = 0;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'X')
            number++;
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

int main(int ac, char **av)
{
    WINDOW *win;
    struct winsize w;
    struct stat sb;
    stat(av[1], &sb);
    ioctl(0, TIOCGWINSZ, &w);
    int columns = w.ws_col / 2;
    int rows = w.ws_row / 2;
    int stringLength;
    int c;
    char **map_2d = malloc(sizeof(char *) * sb.st_size + 1);
    int size = 0;
    int fd;
    int startx = (80 - 30) / 2;
    int starty = (80 - 10) / 2;
    char *buff = malloc(sizeof(char) * sb.st_size + 2);
    int lengthx = 0;
    int lengthy = 0;
    int numberZero = 0;
    int numberCase = 0;
    int tmpPosy = 0;
    int tmpPosx = 0;

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd == - 1) {
        my_putstr("Error with opn\n");
        return (84);
    }
    stringLength = my_strlen(av[1]) / 2;
    size = read(fd, buff, sb.st_size);
    lengthx = length_map_x(buff);
    lengthy = length_map_y(buff);
    map_2d = transform_2d(buff, sb, lengthx);
    columns += stringLength;
    initscr();
    noecho();
    win = newwin(100, 300, startx, starty);
    keypad(win, TRUE);
    curs_set(FALSE);
    refresh();
    numberZero = number_of_answer(buff);
    numberCase = number_of_cases(buff);
    rows = 1;
    columns = 1;
    while (numberZero > 0 && numberCase > 0) {
        clear();
        for (int i = 0; i < lengthy; i++)
            printw("%s", map_2d[i]);
        mvprintw(rows, columns, "P");
        refresh();
        c = wgetch(win);
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
                numberZero = number_of_answer(buff);
                numberCase = number_of_cases(buff);
                map_2d = transform_2d(buff, sb, lengthx);
            default:
                break;
        }
    }
    endwin();
    if (numberCase == 0)
        return (1);
    return 0;
}