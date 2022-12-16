# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:30:28 by dluna-lo          #+#    #+#              #
#    Updated: 2022/12/16 12:11:01 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME = philo

CC		=	gcc
# CFLAGS	=	-g -Wall -Werror -Wextra -pthread -I. -I./$(INCDIR)
CFLAGS	=	-g -Wall -Werror -Wextra -pthread -I. -I./$(INCDIR) -fsanitize=thread
RM		=	rm -f
RM_F		=	rm -rf

# Includes are all .h files
INCDIR	=	libs/
INC		=	libs/philosophers.h

# Sources are all .c files
SRCDIR	=	src/
SRCS =	src/main.c src/ft_check_parameters.c src/ft_check_parameters_utils.c src/ft_create_mutex.c src/ft_init_state.c \
				src/ft_free.c src/ft_get_time.c src/ft_philo.c src/ft_threads.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# ////////////////// TARGETS

# all: $(NAME)
all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	mkdir -p $@

# Removes objects
clean:
	@$(RM_F) $(OBJDIR)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all 

.PHONY:		all clean fclean re header