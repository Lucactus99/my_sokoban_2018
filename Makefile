##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC      =       gcc

SRC     =	main.c \
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
