# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 17:30:28 by dluna-lo          #+#    #+#              #
#    Updated: 2022/12/07 18:35:31 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME = philo
NAME_BONUS = philo_bonus

CC		=	gcc
CFLAGS	=	-g -Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f
RM_F		=	rm -rf

# Includes are all .h files
INCDIR	=	libs/
# INC		=	$(wildcard $(INCDIR)*.h)
INC		=	libs/philosophers.h

INC_BONUS		=	libs/checker.h

# Sources are all .c files
SRCDIR	=	src/
SRCS =	src/main.c

SRCDIR_BONUS	=	bonus/
SRCS_BONUS =	bonus/main.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

OBJDIR_BONUS	=	bin_bonus/
OBJS_BONUS	=	$(patsubst $(SRCDIR_BONUS)%.c,$(OBJDIR_BONUS)%.o,$(SRCS_BONUS))

# ////////////////// TARGETS

# all: $(NAME)
all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Generates output file
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJS_BONUS)

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compiles sources into objects
$(OBJS_BONUS): $(OBJDIR_BONUS)%.o : $(SRCDIR_BONUS)%.c $(INC_BONUS) | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	mkdir -p $@

$(OBJDIR_BONUS):
	mkdir -p $@

# Removes objects
clean:
	@$(RM_F) $(OBJDIR)
	@$(RM_F) $(OBJDIR_BONUS)

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)

# Removes objects and executables and remakes
re: fclean all

bonus: $(NAME_BONUS)

.PHONY:		all clean fclean re header