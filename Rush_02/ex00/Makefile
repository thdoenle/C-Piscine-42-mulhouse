SRCS 	= check_error.c divide_str.c free_tab.c ft_putchar.c ft_is_zero.c \
		  ft_putstr.c ft_str_is_numeric.c \
		  ft_strcpy_malloc.c ft_strlen.c full_tab.c main.c print_grp3.c \
		  print_number.c parse_dict.c \
		  allocate.c append.c calc_nb_lines.c free_str_tabs.c \
		  ft_is_printable.c \
		  ft_is_wspace.c get_next_char.c \
		  parse_key.c parse_value.c sort_dict.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME	= rush-02
HEADER  = rush02.h


all: 		${NAME}

${NAME}:	 ${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o:		%.c ${HEADER}
			${CC} ${CFLAGS} -c $< -o $@

clean:		
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all


