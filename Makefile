# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 19:54:53 by chchour           #+#    #+#              #
#    Updated: 2023/09/07 16:42:38 by chchour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

SRCS = main.c init.c datacollection.c cpy.c make_image-lib.c putstuff.c takefullmap.c verifmap.c move.c pathfinding.c helper.c free.c

OBJS = $(SRCS:.c=.o)

LIBX_DIR = minilibx-linux

LIBP_DIR = ft_printf

LIBX_NAME = libmlx.a

LIBP_NAME = libftprintf.a

CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@
	
$(NAME): $(OBJS)
	make -C $(LIBX_DIR)
	make -C $(LIBP_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBP_DIR)/$(LIBP_NAME) $(LIBX_DIR)/$(LIBX_NAME) -lX11 -lXext -o $(NAME)
	
clean:
	make clean -C $(LIBX_DIR)
	make clean -C $(LIBP_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBP_DIR)
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re
