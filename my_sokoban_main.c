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

char **main_switch(char **map_2d, struct position *pos,
struct number *num, struct length *len)
{
    clear();
    for (int i = 0; i < len->lengthy; i++)
        printw("%s", map_2d[i]);
    mvprintw(pos->rows, pos->columns, "P");
    refresh();
    map_2d = case_switch(pos, num, map_2d, len);
    return (map_2d);
}

int main_loop(struct length *len, struct number *num)
{
    char **map_2d = transform_2d(num, len->lengthx);
    struct position *pos;
    pos = malloc(sizeof(struct position));
    pos->rows = 1;
    pos->columns = 1;
    pos->tmpPosy = 0;
    pos->tmpPosx = 0;
    num->numberZero = number_of_answer(map_2d, len);
    num->numberCase = number_of_cases(map_2d, len);

    if (find_pos_player(map_2d, len, pos) == 84)
        return (84);
    else
        map_2d[pos->rows][pos->columns] = ' ';
    while (num->numberZero > 0 && num->numberCase > 0) {
        map_2d = main_switch(map_2d, pos, num, len);
    }
    if (num->numberCase == 0)
        return (1);
    return (0);
}

int my_sokoban(struct number *num)
{
    struct length *len;
    len = malloc(sizeof(struct length));
    len->lengthx = length_map_x(num->buff);
    len->lengthy = length_map_y(num->buff);
    int value;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    value = main_loop(len, num);
    endwin();
    return (value);
}

int main(int ac, char **av)
{
    int size = 0;
    int fd;
    struct number *num;
    num = malloc(sizeof(struct number));
    num->sb = 1000;
    num->buff = malloc(sizeof(char) * num->sb + 2);

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd == - 1) {
        my_putstr("Error with opn\n");
        return (84);
    }
    size = read(fd, num->buff, num->sb);
    return (my_sokoban(num));
}