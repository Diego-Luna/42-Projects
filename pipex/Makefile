# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 12:49:52 by dluna-lo          #+#    #+#              #
#    Updated: 2022/11/08 11:10:35 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME = pipex

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f

# Includes are all .h files
INCDIR	=	include/
INC		=	$(wildcard $(INCDIR)*.h)

# Sources are all .c files
SRCDIR	=	src/
SRCS = src/main.c src/ft_check_parameters.c src/ft_errors.c src/utils_str.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# ////////////////// TARGETS

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) -o $@ $^

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	$(HIDE)mkdir -p $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all
