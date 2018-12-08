/*
** EPITECH PROJECT, 2018
** my_sokoban
** File description:
** my_sokoban_main
*/

#include "my.h"

int main_loop(struct length *len, struct number *num)
{
    char **map_2d = transform_2d(num, len);
    struct position *pos = malloc(sizeof(struct position));

    initiate_varia(pos, num, map_2d, len);
    if (num->numberZero != num->numberCase)
        return (84);
    if (find_pos_player(map_2d, len, pos) == 84)
        return (84);
    else
        map_2d[pos->rows][pos->columns] = ' ';
    while (num->numberZero > 0 && num->numberCase > 0)
        map_2d = main_switcher(map_2d, pos, num, len);
    clear();
    for (int i = 0; i < len->lengthy; i++)
        printw("%s", map_2d[i]);
    mvprintw(pos->rows, pos->columns, "P");
    refresh();
    if (num->numberCase == 0)
        return (1);
    return (0);
}

int my_sokoban(struct number *num)
{
    struct length *len = malloc(sizeof(struct length));
    int value;

    len->lengthx = length_map_x(num->buff);
    len->lengthy = length_map_y(num->buff);
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    value = main_loop(len, num);
    endwin();
    return (value);
}

void check_error(struct number *num, char **av)
{
    FILE *fp;

    fp = fopen(av[1], "r");
    num->buff = malloc(sizeof(char) * (num->sb + 1));
    fread(num->buff, 1, num->sb, fp);
    num->buff[num->sb] = '\0';
    fclose(fp);
    for (int i = 0; num->buff[i] != '\0'; i++) {
        if (num->buff[i] != '\n' && num->buff[i] != ' ' && num->buff[i] != '#'
        && num->buff[i] != 'P' && num->buff[i] != 'X' && num->buff[i] != 'O')
            exit(84);
    }
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tmap\tfile representing the warehouse map, ");
    my_putstr("containing '#' for walls, \n");
    my_putstr("\t\t'P' for the player, 'X' for boxes and");
    my_putstr(" 'O' for storage locations.\n");
}

int main(int ac, char **av)
{
    FILE *fp;
    struct number *num = malloc(sizeof(struct number));
    ssize_t read = 0;
    size_t len = 0;
    char *line = NULL;

    if ((ac == 2 && my_strcmp(av[1], "-h") == 0) || ac != 2) {
        help();
        return (84);
    }
    fp = fopen(av[1], "r");
    if (fp == NULL)
        return (84);
    while ((read = getline(&line, &len, fp)) != -1)
        num->sb += read;
    if (line)
        free(line);
    fclose(fp);
    check_error(num, av);
    return (my_sokoban(num));
}