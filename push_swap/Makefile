################################################################################
#                                     CONFIG                                   #
################################################################################


# Program
NAME = push_swap

CC		=	gcc
CFLAGS	=	-g -Wall -Werror -Wextra -I. -I./$(INCDIR)
RM		=	rm -f
RM_F		=	rm -rf

# Includes are all .h files
INCDIR	=	libs/
# INC		=	$(wildcard $(INCDIR)*.h)
INC		=	libs/push_swap.h

# Sources are all .c files
SRCDIR	=	src/
SRCS =	src/main.c src/ft_sa_sb_ss.c src/ft_pa_pb.c src/ft_rra_rrb_rrr.c \
				src/ft_ra_rb_rr.c src/ft_arrange_2_to_5_format.c src/ft_exit.c \
				src/ft_arrange_big.c src/ft_check_params.c src/ft_tlist_utils.c

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
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(D_LIBFT)$(LIBFT)

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