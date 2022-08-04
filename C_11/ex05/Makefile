SRCS	= ft_atoi.c ft_putnbr.c ft_putstr.c ft_calc_ft.c main.c
OBJS	= $(SRCS:%.c=%.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
NAME	= do-op

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
