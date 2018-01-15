# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:25:37 by ybohusev          #+#    #+#              #
#    Updated: 2018/01/15 15:25:38 by ybohusev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

FILLIT_PATH = ./srcs/
LIBFT_PATH = ./includes/libft/
INC_PATH = ./includes/

SRC = $(addprefix $(FILLIT_PATH),$(SRC_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = fillit.h

SRC_NAME = 

SRC_NAME += algor.c
SRC_NAME += check_valid.c
SRC_NAME += display_data.c
SRC_NAME += extr.c
SRC_NAME += fillit_lstadd.c
SRC_NAME += fillit_lstnew.c
SRC_NAME += fillit_memalloc.c
SRC_NAME += main.c
SRC_NAME += move_tetrimino.c
SRC_NAME += read_data.c
SRC_NAME += write_data.c

all: $(NAME)

$(NAME): $(OBJ_NAME)
	make -C $(LIBFT_PATH)
	$(CC) $(CC_FLAGS) -o $(NAME) $(OBJ_NAME) $(LIBFT_PATH)/libft.a

%.o: $(FILLIT_PATH)%.c
	$(CC) $(CC_FLAGS) $(INC) -c $<

clean:
	make -C $(LIBFT_PATH) clean
	rm -f $(OBJ_NAME)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all