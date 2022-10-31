# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 11:37:17 by dluna-lo          #+#    #+#              #
#    Updated: 2022/10/31 15:28:47 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	src/ft_printf.c src/ft_print_and_length.c src/ft_percent_controller.c \
				src/ft_result/ft_result_s_c.c src/ft_result/ft_result_xsp.c \
				src/ft_putnbr_base.c src/ft_result/ft_result_di_u.c src/utils/utils.c

OBJS = ${SRCS:.c=.o}

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