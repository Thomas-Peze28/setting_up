##
## EPITECH PROJECT, 2024
## makefile pong seb
## File description:
## makfile
##

SRC	=	src/main.c	\
		src/setting_up.c	\
		src/mem_alloc_2d_array.c	\
		src/mem_dup_2d_array.c	\
		src/load_2d_arr_from_file.c	\
		src/return_file_lenght.c	\
		src/return_map_dim.c	\
		src/create_map.c	\

NAME	=	setting_up

OBJ	=	$(SRC:.c=.o)

CFLAGS += -I./include/ -L./lib/my -lmy -Wall -Wextra

all: build_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

build_lib:
		make -C ./lib/my/

clean_lib:
		make clean -C ./lib/my/

clean: clean_lib
	rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

run: re
	./$(NAME)

.PHONY: all fclean clean re
