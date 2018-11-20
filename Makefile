##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =       gcc

SRC     =	my_sokoban_main.c \
		my_sokoban_get.c \
		my_sokoban_moves.c \
		my_sokoban_switch.c \
		my_sokoban_display.c \
		src/my_strlen.c \
		src/my_putstr.c \
		src/my_putchar.c

OBJ     =       $(SRC:.c=.o)

NAME    =       my_sokoban

CFLAGS  =       -W -Wall -ansi -pedantic -g -std=c99 -I include

all:    $(NAME)

$(NAME):        $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
