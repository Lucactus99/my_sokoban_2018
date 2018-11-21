/*
** EPITECH PROJECT, 2018
** h
** File description:
** h
*/

#ifndef MY_H_
#define MY_H_

#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct position {
    int rows;
    int columns;
    int tmpPosy;
    int tmpPosx;
};
struct length {
    int lengthy;
    int lengthx;
};
struct number {
    int numberZero;
    int numberCase;
    int sb;
    char *buff;
};
void my_putchar(char);
int my_putstr(char const *);
int my_strlen(char const *);
char **transform_2d(struct number *, int);
int number_of_answer(char **, struct length *);
int number_of_cases(char **, struct length *);
void left_main(char **, struct position *, struct number *);
void right_main(char **, struct position *, struct number *);
void up_main(char **, struct position *, struct number *);
void down_main(char **, struct position *, struct number *);
int length_map_x(char *);
int length_map_y(char *);
void left_main_check_last_pos(char **, struct position *, struct number *);
void right_main_check_last_pos(char **, struct position *, struct number *);
void up_main_check_last_pos(char **, struct position *, struct number *);
void down_main_check_last_pos(char **, struct position *, struct number *);
int check_moves_left(char **, struct position *);
int check_moves_right(char **, struct position *);
int check_moves_up(char **, struct position *);
int check_moves_down(char **, struct position *);
int find_pos_player(char **, struct length *, struct position *);
char **restart_game(struct position *, struct number *,
char **, struct length *);
char **case_switch(struct position *, struct number *,
char **, struct length *);

#endif //MY_H_
