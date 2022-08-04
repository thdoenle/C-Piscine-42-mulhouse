# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 19:34:00 by thdoenle          #+#    #+#              #
#    Updated: 2022/08/03 19:41:21 by thdoenle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS	:= $(SRCS:%=srcs/%)
OBJS	= $(SRCS:.c=.o)
HEADER	= includes/ft.h
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= libft.a

all:	$(NAME)

$(NAME):	$(OBJS)
	ar rc $@ $^

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
