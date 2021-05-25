##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## generator dante's star
##

SRC     =       src/main.c\
		src/perfect_maze.c\
		src/create_maze.c\
		lib/my_getnbr.c\
		lib/my_putstr.c\
		lib/my_putchar.c

OBJ     =       $(SRC:.c=.o)

NAME    =       generator

CFLAGS =        -I ./include/ -o3 -g3

all:            $(NAME)

$(NAME):        $(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:         clean
		rm -f $(NAME)
		rm -f include/*~
		rm -f src/*~
		rm -f src/#~
		rm -f *~

re:             fclean all

.PHONY:         all clean fclean re
