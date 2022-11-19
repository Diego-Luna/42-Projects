# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:59:37 by dluna-lo          #+#    #+#              #
#    Updated: 2022/11/15 15:10:37 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Sources are all .c files
SRCDIR	=	src/
SRCS	=	src/ft_isalpha.c src/ft_isalnum.c src/ft_isdigit.c src/ft_isprint.c src/ft_isascii.c \
				src/ft_atoi.c src/ft_itoa.c src/ft_putnbr_fd.c src/ft_putstr_fd.c src/ft_putchar_fd.c \
				src/ft_putendl_fd.c src/ft_strdup.c src/ft_calloc.c src/ft_substr.c src/ft_memset.c \
				src/ft_memchr.c src/ft_memcpy.c src/ft_memmove.c src/ft_memcmp.c src/ft_tolower.c \
				src/ft_toupper.c src/ft_strlen.c src/ft_bzero.c src/ft_strchr.c src/ft_strrchr.c \
				src/ft_split.c src/ft_strjoin.c src/ft_strtrim.c src/ft_strlcat.c src/ft_strncmp.c \
				src/ft_striteri.c src/ft_strlcpy.c src/ft_strmapi.c src/ft_strnstr.c \
				src/ft_lstsize.c src/ft_lstlast.c src/ft_lstnew.c src/ft_lstadd_back.c src/ft_lstadd_front.c \
				src/ft_lstiter.c src/ft_lstdelone.c src/ft_lstclear.c src/ft_lstmap.c \
				src/ft_printf.c src/ft_print_and_length.c src/ft_percent_controller.c \
				src/ft_result_s_c.c src/ft_result_xsp.c \
				src/ft_putnbr_base.c src/ft_result_di_u.c \
				src/get_next_line.c src/get_next_line_utils.c

# OBJS			= $(SRCS:.c=.o)
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

INC		=	libft.h

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	mkdir -p $@

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all
