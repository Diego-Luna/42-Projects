# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 10:00:31 by tmatis            #+#    #+#              #
#    Updated: 2022/11/16 13:16:16 by dluna-lo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################


# Program
NAME = so_long

CC		=	gcc
CFLAGS	=	-g -Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f
RM_F		=	rm -rf

# Includes are all .h files
INCDIR	=	libs/
# INC		=	$(wildcard $(INCDIR)*.h)
INC		=	libs/so_long.h

# Sources are all .c files
SRCDIR	=	src/
SRCS =	src/main.c src/ft_read_file.c src/ft_error.c src/ft_create_map.c

# Objects are all .o files
OBJDIR	=	bin/
OBJS	=	$(patsubst $(SRCDIR)%.c,$(OBJDIR)%.o,$(SRCS))

# libf
LIBFT = libft.a
D_LIBFT = libs/libft/

# ////////////////// TARGETS

# all: $(NAME)
all: do_libft $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(CC) -lmlx -framework OpenGL -framework AppKit -o $@ $(OBJS) $(D_LIBFT)$(LIBFT)

# Compiles sources into objects
$(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.c $(INC) | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Creates directory for binaries
$(OBJDIR):
	mkdir -p $@

# Removes objects
clean:
	@$(RM_F) $(OBJDIR)
	@$(MAKE) --no-print-directory -C $(D_LIBFT) clean

# Removes objects and executables
fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) --no-print-directory -C $(D_LIBFT) fclean

# Removes objects and executables and remakes
re: fclean all

# libf
do_libft:
	@$(MAKE) -C $(D_LIBFT)
# libf
.PHONY:		all clean fclean re header
