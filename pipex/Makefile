# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 12:49:52 by dluna-lo          #+#    #+#              #
#    Updated: 2022/11/12 17:32:25 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program
NAME = pipex
NAME_BONUS = pipex_bonus

CC		=	gcc
CFLAGS	=	-g -Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f

# Includes are all .h files
INCDIR	=	libs/
# INC		=	$(wildcard $(INCDIR)*.h)
INC		=	libs/pipex.h
INC_BONUS		=	libs/pipex_bonus.h

# Sources are all .c files
SRCDIR	=	src/
SRCS =	src/main.c src/ft_check_parameters.c src/ft_errors.c \
				src/ft_childs.c src/ft_father.c src/ft_get_paht.c

SRCDIR_BONUS	=	src_bonus/
SRCS_BONUS =	src_bonus/main_bonus.c src_bonus/ft_check_parameters_bonus.c \
				src_bonus/ft_errors_bonus.c src_bonus/ft_childs_bonus.c \
				src_bonus/ft_father_bonus.c src_bonus/ft_get_paht_bonus.c \
				src_bonus/ft_file_bonus_bonus.c src_bonus/ft_pipe_bonus.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

OBJDIR_BONUS	=	bin_bonus/
OBJS_BONUS	=	$(patsubst $(SRCDIR_BONUS)%.c,$(OBJDIR_BONUS)%.o,$(SRCS_BONUS))

# libf
LIBFT = libft.a
D_LIBFT = libs/libft/

# ////////////////// TARGETS

# all: $(NAME)
all: do_libft $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(D_LIBFT)$(LIBFT)

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ***** Bonus
# Generates output file
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) -o $@ $(OBJS_BONUS) $(D_LIBFT)$(LIBFT)

$(OBJS_BONUS): $(OBJDIR_BONUS)%.o : $(SRCDIR_BONUS)%.c $(INC_BONUS) | $(OBJDIR_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	mkdir -p $@

# ***** Bonus
$(OBJDIR_BONUS):
	mkdir -p $@

# Removes objects
clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS)
	@$(MAKE) --no-print-directory -C $(D_LIBFT) clean

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C $(D_LIBFT) fclean

# Removes objects and executables and remakes
re: fclean all

# ***** Bonus
bonus: do_libft $(NAME_BONUS)

# libf
do_libft:
	@$(MAKE) -C $(D_LIBFT)
# libf

.PHONY: all clean fclean re