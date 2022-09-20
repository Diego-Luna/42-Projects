NAME = push_swap.a

SRCS =	main.c ./src/libft.c

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