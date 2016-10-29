# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcortina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/08 13:52:12 by gcortina          #+#    #+#              #
#    Updated: 2016/10/29 15:25:17 by gcortina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = ./include/
SRCDIR = ./src/
LIB = ./libft/libft.a
LIBINC = -I./libft
LIBLINK = -L./libft -lft
FLAGS = -Wall -Wextra -Werror
CC = gcc
OPTIONS = -I $(HEADER) $(FLAGS)
SRC_FILES = main.c ft_rdfile.c ft_valid.c fetch_mino.c minos_count.c mapit.c split_minos.c solver.c ft_concat.c need_space.c insert.c \
			erase.c check_next.c
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJ_NAME = $(SRC_FILES:.c=.o)

all: libft $(NAME)

libft: $(LIB)

$(LIB):
	make -C ./libft

$(NAME):
	$(CC) $(LIBINC) $(LIBLINK) $(OPTIONS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
