# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 14:02:20 by anacamilalu       #+#    #+#              #
#    Updated: 2022/10/20 15:49:29 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	src/ft_printf.c src/ft_check_params.c src/ft_convert.c src/str_1.c src/str_2.c src/str_3.c src/strt_to_number.c \
				src/ft_result/ft_result_di_u.c src/ft_result/ft_result_s_c.c src/ft_result/ft_result_x.c \
				src/test/ft_atoi.c src/test/ft_isdigit.c src/test/ft_putstr_fd.c src/test/ft_strlen.c

OBJS = ${SRCS:.c=.o}


OBJS			= $(SRCS:.c=.o)

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all