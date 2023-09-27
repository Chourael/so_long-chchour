# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchour <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 13:52:54 by chchour           #+#    #+#              #
#    Updated: 2023/04/27 12:16:49 by chchour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=		./ft_printf.c \
			./ft_c.c \
			./ft_s.c \
			./ft_di.c \
			./ft_u.c \
			./ft_x.c \
			./ft_xmaj.c\
			./ft_p.c\

OBJS	=		$(SRCS:.c=.o)

NAME	=		libftprintf.a

CC	=		cc

CFLAGS	=		-Wall -Werror -Wextra

all:			$(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@ -I.

$(NAME): $(OBJS)
	ar -crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
