##
## EPITECH PROJECT, 2018
## Sokoban
## File description:
## makefile
##

SRC 	=	main.c \
		sokoban.c \
		usage.c \
		map.c \
		move.c \
		boxes.c \
		status.c \
		reset.c \
		check.c
OBJ	=	$(SRC:.c=.o)
NAME	=	my_sokoban
CFLAGS	=	-g -std=c11 -Wall -Wextra -Iinclude
LDFLAGS	=	-lncurses -Llib/my -lmy
LIB	=	lib/my/libmy.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

$(LIB):
	make -C lib/my

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C lib/my fclean

re: fclean all
