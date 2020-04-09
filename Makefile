##
## EPITECH PROJECT, 2019
## My_RPG
## File description:
## Makefile
##

DEBUG ?= 0
ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -W -Iinclude
else
	CFLAGS = -W -Iinclude
endif

CC = gcc

RM = rm -vf

NAME = my_rpg

SRC_DIR = src

SRC = $(SRC_DIR)/main.c							\
	  $(SRC_DIR)/init.c							\
	  $(SRC_DIR)/window.c						\
	  $(SRC_DIR)/scene.c						\
	  $(SRC_DIR)/file_parsing.c					\
	  $(SRC_DIR)/game_loop_management.c			\
	  $(SRC_DIR)/set_ressources.c
	  
LDFLAGS = -Llib -lmy -l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib/libmy.a $(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
		$(CC) --coverage -g3 -W -Iinclude $(SRC) -c
		$(CC) -g3 -W -Iinclude $(TEST) -c
		$(CC) -o unit_tests *.o -lcriterion -lgcov
		./unit_tests
		gcovr
		gcovr -b

lib/libmy.a:
	$(MAKE) -C lib/my NAME=../libmy.a

clean:
	$(RM) $(OBJ)
	$(MAKE) -C lib/my clean NAME=../libmy.a


fclean:
	$(RM) $(OBJ) $(NAME)
	$(MAKE) -C lib/my fclean NAME=../libmy.a

re : fclean all

.PHONY: all clean fclean re tests_run
