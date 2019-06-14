##
## EPITECH PROJECT, 2018
## Sokoban
## File description:
## makefile
##

SRC 	=	main.c \
		sokoban.c \
		sokoban2.c \
		usage.c \
		map.c \
		map2.c \
		move.c \
		boxes.c \
		status.c \
		reset.c \
		check.c \
		colors.c \
		map_pack.c \
		main_menu.c \
		solo_menu.c \
		ai.c
OBJ	=	$(SRC:.c=.o)
NAME	=	my_sokoban
CFLAGS	=	-D _DEFAULT_SOURCE -O3 -std=c11 -Wall -Wextra -Iinclude
LDFLAGS	=	-lncurses -L../lib/my -lmy
LIB	=	../lib/my/libmy.a

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

$(LIB):
	make -C ../lib/my

clean:
	rm -f $(OBJ)
	make -C ../lib/my clean

fclean: clean
	rm -f $(NAME)
	make -C ../lib/my fclean

re: fclean all
